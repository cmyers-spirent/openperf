#include <errno.h>
#include <getopt.h>
#include <stdlib.h>
#include <stdio.h>

#include "core/icp_log.h"
#include "core/icp_options.h"

static struct icp_options_data_list _options_list = LIST_HEAD_INITIALIZER(_options_list);

static void __attribute__((noreturn)) _usage(const char *program_name)
{
    FILE *output = stderr;

    fprintf(output, "Usage: %s\n\n", program_name);
    fprintf(output, "Options:\n");

    struct icp_options_data *opt_data = NULL;
    LIST_FOREACH(opt_data, &_options_list, next) {
        for (const struct icp_option *curr = opt_data->options;
             curr->description != NULL;
             curr++) {
            fprintf(output, "  -%c, --%-22s%s\n",
                    curr->short_opt, curr->long_opt, curr->description);
        }
    }

    exit(EXIT_SUCCESS);
}

int icp_options_init()
{
    struct icp_options_data *opt_data = NULL;
    LIST_FOREACH(opt_data, &_options_list, next) {
        if (opt_data->init) {
            if (opt_data->init(opt_data->data) != 0) {
                icp_log(ICP_LOG_ERROR, "Failed to initialize %s options\n", opt_data->name);
            }
        }
    }

    return (0);
}

struct icp_options_data * _find_options_data(int opt)
{
    struct icp_options_data *opt_data = NULL;
    LIST_FOREACH(opt_data, &_options_list, next) {
        for (const struct icp_option *curr = opt_data->options;
             curr->description != NULL;
             curr++) {
            if (curr->short_opt == opt) {
                return (opt_data);
            }
        }
    }
    return (NULL);
}

int _allocate_optstring(char **optstringp)
{
    /* Figure out necessary string length */
    int length = 1;  /* include trailing null */
    struct icp_options_data *opt_data = NULL;
    LIST_FOREACH(opt_data, &_options_list, next) {
        for (const struct icp_option *curr = opt_data->options;
             curr->description != NULL;
             curr++) {
            length += curr->has_arg ? 2 : 1;
        }
    }

    /* Allocate suffidient length */
    char *optstring = calloc(1, length);
    if (!optstring) {
        return (-ENOMEM);
    }

    /* Fill in string */
    unsigned idx = 0;
    LIST_FOREACH(opt_data, &_options_list, next) {
        for (const struct icp_option *curr = opt_data->options;
             curr->description != NULL;
             curr++) {
            optstring[idx++] = curr->short_opt;
            if (curr->has_arg) {
                optstring[idx++] = ':';
            }
        }
    }

    *optstringp = optstring;
    return (0);
}

int _allocate_longopts(struct option **longoptsp)
{
    /* Figure out necessary longopts length */
    int nb_opts = 1;  /* include null terminated ending */
    struct icp_options_data *opt_data = NULL;
    LIST_FOREACH(opt_data, &_options_list, next) {
        for (const struct icp_option *curr = opt_data->options;
             curr->description != NULL;
             curr++) {
            nb_opts++;
        }
    }

    struct option *longopts = calloc(nb_opts, sizeof(*longopts));
    if (!longopts) {
        return (-ENOMEM);
    }

    /* Fill in longopts */
    unsigned idx = 0;
    LIST_FOREACH(opt_data, &_options_list, next) {
        for (const struct icp_option *curr = opt_data->options;
             curr->description != NULL;
             curr++) {
            longopts[idx++] = (struct option){
                curr->long_opt,
                curr->has_arg,
                NULL,
                curr->short_opt
            };
        }
    }

    *longoptsp = longopts;
    return (0);
}

int icp_options_parse(int argc, char *argv[])
{
    optind = 1;  /* magic variable for getopt */
    opterr = 1;

    char *optstring = NULL;
    int error = _allocate_optstring(&optstring);
    if (error) {
        return (error);
    }

    struct option *longopts = NULL;
    if ((error = _allocate_longopts(&longopts)) != 0) {
        free(optstring);
        return (error);
    }

    for (;;) {
        int option_index = 0;
        int opt = getopt_long(argc, argv, optstring, longopts, &option_index);
        if (opt == -1) {
            break;
        }
        if (opt == '?' || opt == 'h') {
            /* unspecified option */
            _usage(argv[0]);
        }
        struct icp_options_data *opt_data = _find_options_data(opt);
        if (opt_data->callback) {
            opt_data->callback(opt, optarg, opt_data->data);
        }
    }

    free(optstring);
    free(longopts);
    return (0);
}

void icp_options_register(struct icp_options_data *opt_data)
{
    LIST_INSERT_HEAD(&_options_list, opt_data, next);
}

/*
 * Register the help option.
 * Note: we don't register any callbacks because we can handle them directly.
 * Additionally, there is no mechanism to get argv, which we need for calling
 * usage.
 */
static struct icp_options_data help_option = {
    .name = "help",
    .init = NULL,
    .callback = NULL,
    .data = NULL,
    .options = {
        { "Print this message.", "help", 'h', 0 },
        { 0, 0, 0, 0 },
    }
};

REGISTER_OPTIONS(help_option)