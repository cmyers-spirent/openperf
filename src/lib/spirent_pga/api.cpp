#include "api.h"
#include "common/fill.h"
#include "common/prbs.h"
#include "common/signature.h"
#include "common/verify.h"
#include "functions.h"
#include "instruction_set.h"

static void pga_log_implementation_info(FILE* output, std::string_view function, std::string_view instructions)
{
    fprintf(output, "spirent_pga: using %.*s instructions for %.*s\n",
            static_cast<int>(instructions.size()), instructions.data(),
            static_cast<int>(function.size()), function.data());
}

extern "C" {

void pga_init()
{
    auto& functions = pga::functions::instance();
    (void)functions;
}


void pga_log_info(FILE* output)
{
    auto& functions = pga::functions::instance();

    pga_log_implementation_info(output, functions.decode_signatures_impl.name,
                                pga::instruction_set::to_string(
                                    pga::get_instruction_set(functions.decode_signatures_impl)));
    pga_log_implementation_info(output, functions.encode_signatures_impl.name,
                                pga::instruction_set::to_string(
                                    pga::get_instruction_set(functions.encode_signatures_impl)));
    pga_log_implementation_info(output, functions.fill_step_aligned_impl.name,
                                pga::instruction_set::to_string(
                                    pga::get_instruction_set(functions.fill_step_aligned_impl)));
    pga_log_implementation_info(output, functions.fill_prbs_aligned_impl.name,
                                pga::instruction_set::to_string(
                                    pga::get_instruction_set(functions.fill_prbs_aligned_impl)));
    pga_log_implementation_info(output, functions.verify_prbs_aligned_impl.name,
                                pga::instruction_set::to_string(
                                    pga::get_instruction_set(functions.verify_prbs_aligned_impl)));
}

int pga_signature_flag(enum pga_signature_prbs prbs, enum pga_signature_timestamp ts)
{
    int flags = 0;
    if (prbs == pga_signature_prbs::enable) {
        flags += (1 << 1);
    }
    if (ts == pga_signature_timestamp::last) {
        flags += (1 << 0);
    }

    return (flags);
}

enum pga_signature_prbs pga_prbs_flag(int flags)
{
    return (flags & (1 << 1)
            ? pga_signature_prbs::enable
            : pga_signature_prbs::disable);
}

enum pga_signature_timestamp pga_timestamp_flag(int flags)
{
    return (flags & (1 << 0)
            ? pga_signature_timestamp::last
            : pga_signature_timestamp::first);
}

uint16_t pga_signatures_decode(const uint8_t* payloads[], uint16_t count,
                               uint32_t stream_ids[],
                               uint32_t sequence_numbers[],
                               uint64_t tx_timestamps[],
                               int flags[])
{
    return (pga::signature::decode(payloads, count,
                                   stream_ids, sequence_numbers,
                                   tx_timestamps, flags));
}

void pga_signatures_encode(uint8_t* destinations[],
                           const uint32_t stream_ids[],
                           const uint32_t sequence_numbers[],
                           uint64_t timestamp, int flags, uint16_t count)
{
    pga::signature::encode(destinations,
                           stream_ids, sequence_numbers,
                           timestamp, flags, count);
}

void pga_fill_incr(uint8_t* payloads[], uint16_t lengths[], uint16_t count, uint8_t base)
{
    for (uint16_t i = 0; i < count; i++) {
        pga::fill::incr(payloads[i], lengths[i], base);
    }
}

uint32_t pga_fill_prbs(uint8_t* payloads[], uint16_t lengths[], uint16_t count,
                       uint32_t seed)
{
    for (uint16_t i = 0; i < count; i++) {
        seed = pga::fill::prbs(payloads[i], lengths[i], seed);
    }

    return (seed);
}

bool pga_verify_prbs(uint8_t* payloads[], uint16_t lengths[], uint16_t count,
                     uint32_t bit_errors[])
{
    for (uint16_t i = 0; i < count; i++) {
        bit_errors[i] = pga::verify::prbs(payloads[i], lengths[i]);
    }

    return (std::any_of(bit_errors, bit_errors + count,
                        [](auto& value) { return (value); }));
}

}