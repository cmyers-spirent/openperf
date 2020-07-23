#include <string_view>
#include "crash_handler.h"
#include "client/linux/handler/exception_handler.h"

bool op_crash_handler(const google_breakpad::MinidumpDescriptor& descriptor,
                      void* context,
                      bool succeeded)
{
    printf("Dump path: %s\n", descriptor.path());
    return succeeded;
}

void op_crash_handler_init(void)
{
    char crash_dump_dir[PATH_MAX];
    getcwd(crash_dump_dir, sizeof(crash_dump_dir));
    static google_breakpad::MinidumpDescriptor md(crash_dump_dir);
    static google_breakpad::ExceptionHandler eh(
        md, NULL, op_crash_handler, NULL, true, -1);
}