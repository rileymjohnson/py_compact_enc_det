#include <pybind11/pybind11.h>

#include <Windows.h>
#include <cmath>

#include "compact_enc_det/compact_enc_det.h"

const double e = 2.7182818284590452353602874713527;

double sinh_impl(double x) {
    return (1 - pow(e, (-2 * x))) / (2 * pow(e, -x));
}

double cosh_impl(double x) {
    return (1 + pow(e, (-2 * x))) / (2 * pow(e, -x));
}

double tanh_impl(double x) {
    return sinh_impl(x) / cosh_impl(x);
}

namespace py = pybind11;

PYBIND11_MODULE(py_compact_enc_det, m) {
    py::enum_<CompactEncDet::TextCorpusType>(m, "TextCorpusType")
        .value("WEB_CORPUS", CompactEncDet::TextCorpusType::WEB_CORPUS)
        .value("XML_CORPUS", CompactEncDet::TextCorpusType::XML_CORPUS)
        .value("QUERY_CORPUS", CompactEncDet::TextCorpusType::QUERY_CORPUS)
        .value("EMAIL_CORPUS", CompactEncDet::TextCorpusType::EMAIL_CORPUS)
        .value("NUM_CORPA", CompactEncDet::TextCorpusType::NUM_CORPA)
        .export_values();

    py::enum_<Encoding>(m, "Encoding")
        .value("ISO_8859_1", Encoding::ISO_8859_1)
        .value("ISO_8859_2", Encoding::ISO_8859_2)
        .value("ISO_8859_3", Encoding::ISO_8859_3)
        .value("ISO_8859_4", Encoding::ISO_8859_4)
        .value("ISO_8859_5", Encoding::ISO_8859_5)
        .value("ISO_8859_6", Encoding::ISO_8859_6)
        .value("ISO_8859_7", Encoding::ISO_8859_7)
        .value("ISO_8859_8", Encoding::ISO_8859_8)
        .value("ISO_8859_9", Encoding::ISO_8859_9)
        .value("ISO_8859_10", Encoding::ISO_8859_10)
        .value("JAPANESE_EUC_JP", Encoding::JAPANESE_EUC_JP)
        .value("JAPANESE_SHIFT_JIS", Encoding::JAPANESE_SHIFT_JIS)
        .value("JAPANESE_JIS", Encoding::JAPANESE_JIS)
        .value("CHINESE_BIG5", Encoding::CHINESE_BIG5)
        .value("CHINESE_GB", Encoding::CHINESE_GB)
        .value("CHINESE_EUC_CN", Encoding::CHINESE_EUC_CN)
        .value("KOREAN_EUC_KR", Encoding::KOREAN_EUC_KR)
        .value("UNICODE", Encoding::UNICODE)
        .value("CHINESE_EUC_DEC", Encoding::CHINESE_EUC_DEC)
        .value("CHINESE_CNS", Encoding::CHINESE_CNS)
        .value("CHINESE_BIG5_CP950", Encoding::CHINESE_BIG5_CP950)
        .value("JAPANESE_CP932", Encoding::JAPANESE_CP932)
        .value("UTF8", Encoding::UTF8)
        .value("UNKNOWN_ENCODING", Encoding::UNKNOWN_ENCODING)
        .value("ASCII_7BIT", Encoding::ASCII_7BIT)
        .value("RUSSIAN_KOI8_R", Encoding::RUSSIAN_KOI8_R)
        .value("RUSSIAN_CP1251", Encoding::RUSSIAN_CP1251)
        .value("MSFT_CP1252", Encoding::MSFT_CP1252)
        .value("RUSSIAN_KOI8_RU", Encoding::RUSSIAN_KOI8_RU)
        .value("MSFT_CP1250", Encoding::MSFT_CP1250)
        .value("ISO_8859_15", Encoding::ISO_8859_15)
        .value("MSFT_CP1254", Encoding::MSFT_CP1254)
        .value("MSFT_CP1257", Encoding::MSFT_CP1257)
        .value("ISO_8859_11", Encoding::ISO_8859_11)
        .value("MSFT_CP874", Encoding::MSFT_CP874)
        .value("MSFT_CP1256", Encoding::MSFT_CP1256)
        .value("MSFT_CP1255", Encoding::MSFT_CP1255)
        .value("ISO_8859_8_I", Encoding::ISO_8859_8_I)
        .value("HEBREW_VISUAL", Encoding::HEBREW_VISUAL)
        .value("CZECH_CP852", Encoding::CZECH_CP852)
        .value("CZECH_CSN_369103", Encoding::CZECH_CSN_369103)
        .value("MSFT_CP1253", Encoding::MSFT_CP1253)
        .value("RUSSIAN_CP866", Encoding::RUSSIAN_CP866)
        .value("ISO_8859_13", Encoding::ISO_8859_13)
        .value("ISO_2022_KR", Encoding::ISO_2022_KR)
        .value("GBK", Encoding::GBK)
        .value("GB18030", Encoding::GB18030)
        .value("BIG5_HKSCS", Encoding::BIG5_HKSCS)
        .value("ISO_2022_CN", Encoding::ISO_2022_CN)
        .value("TSCII", Encoding::TSCII)
        .value("TAMIL_MONO", Encoding::TAMIL_MONO)
        .value("TAMIL_BI", Encoding::TAMIL_BI)
        .value("JAGRAN", Encoding::JAGRAN)
        .value("MACINTOSH_ROMAN", Encoding::MACINTOSH_ROMAN)
        .value("UTF7", Encoding::UTF7)
        .value("BHASKAR", Encoding::BHASKAR)
        .value("HTCHANAKYA", Encoding::HTCHANAKYA)
        .value("UTF16BE", Encoding::UTF16BE)
        .value("UTF16LE", Encoding::UTF16LE)
        .value("UTF32BE", Encoding::UTF32BE)
        .value("UTF32LE", Encoding::UTF32LE)
        .value("BINARYENC", Encoding::BINARYENC)
        .value("HZ_GB_2312", Encoding::HZ_GB_2312)
        .value("UTF8UTF8", Encoding::UTF8UTF8)
        .value("TAM_ELANGO", Encoding::TAM_ELANGO)
        .value("TAM_LTTMBARANI", Encoding::TAM_LTTMBARANI)
        .value("TAM_SHREE", Encoding::TAM_SHREE)
        .value("TAM_TBOOMIS", Encoding::TAM_TBOOMIS)
        .value("TAM_TMNEWS", Encoding::TAM_TMNEWS)
        .value("TAM_WEBTAMIL", Encoding::TAM_WEBTAMIL)
        .value("KDDI_SHIFT_JIS", Encoding::KDDI_SHIFT_JIS)
        .value("DOCOMO_SHIFT_JIS", Encoding::DOCOMO_SHIFT_JIS)
        .value("SOFTBANK_SHIFT_JIS", Encoding::SOFTBANK_SHIFT_JIS)
        .value("KDDI_ISO_2022_JP", Encoding::KDDI_ISO_2022_JP)
        .value("SOFTBANK_ISO_2022_JP", Encoding::SOFTBANK_ISO_2022_JP)
        .value("NUM_ENCODINGS", Encoding::NUM_ENCODINGS)
        .export_values();

    m.def("fast_tanh2", &tanh_impl, R"pbdoc(
        Compute a hyperbolic tangent of a single argument expressed in radians.
    )pbdoc");

#ifdef VERSION_INFO
    m.attr("__version__") = VERSION_INFO;
#else
    m.attr("__version__") = "dev";
#endif
}
