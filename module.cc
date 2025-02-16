#include <pybind11/pybind11.h>

#include <tuple>
#include <string>

#include "compact_enc_det/compact_enc_det.h"

std::tuple<Encoding, int, bool> Binding_DetectEncoding(
    const std::string& text,
    int text_length,
    const std::string& url_hint,
    const std::string& http_charset_hint,
    const std::string& meta_charset_hint,
    const int encoding_hint,
    const Language language_hint,
    const CompactEncDet::TextCorpusType corpus_type,
    bool ignore_7bit_mail_encodings
) {
    int bytes_consumed;
    bool is_reliable;

    auto encoding = CompactEncDet::DetectEncoding(
        text.c_str(),
        text_length,
        url_hint.c_str(),
        http_charset_hint.c_str(),
        meta_charset_hint.c_str(),
        encoding_hint,
        language_hint,
        corpus_type,
        ignore_7bit_mail_encodings,
        &bytes_consumed,
        &is_reliable
    );

    return { encoding, bytes_consumed, is_reliable };
}

int Binding_BackmapEncodingToRankedEncoding(Encoding enc) {
    return CompactEncDet::BackmapEncodingToRankedEncoding(enc);
}

Encoding Binding_TopEncodingOfLangHint(const std::string& name) {
    return CompactEncDet::TopEncodingOfLangHint(name.c_str());
}

Encoding Binding_TopEncodingOfTLDHint(const std::string& name) {
    return CompactEncDet::TopEncodingOfTLDHint(name.c_str());
}

Encoding Binding_TopEncodingOfCharsetHint(const std::string& name) {
    return CompactEncDet::TopEncodingOfCharsetHint(name.c_str());
}

std::string Binding_Version() {
    return { CompactEncDet::Version() };
}

namespace py = pybind11;

PYBIND11_MODULE(py_compact_enc_det, m) {
    m.def(
        "DetectEncoding",
        &Binding_DetectEncoding,
        py::arg("text"),
        py::arg("text_length"),
        py::arg("url_hint"),
        py::arg("http_charset_hint"),
        py::arg("meta_charset_hint"),
        py::arg("encoding_hint"),
        py::arg("language_hint"),
        py::arg("corpus_type"),
        py::arg("ignore_7bit_mail_encodings")
    );
    
    m.def("BackmapEncodingToRankedEncoding", &Binding_BackmapEncodingToRankedEncoding, py::arg("enc"));
    
    m.def("TopEncodingOfLangHint", &Binding_TopEncodingOfLangHint, py::arg("name"));

    m.def("TopEncodingOfTLDHint", &Binding_TopEncodingOfTLDHint, py::arg("name"));

    m.def("TopEncodingOfCharsetHint", &Binding_TopEncodingOfCharsetHint, py::arg("name"));

    m.def("Version", &Binding_Version);

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

    py::enum_<Language>(m, "Language")
        .value("ENGLISH", Language::ENGLISH)
        .value("DANISH", Language::DANISH)
        .value("DUTCH", Language::DUTCH)
        .value("FINNISH", Language::FINNISH)
        .value("FRENCH", Language::FRENCH)
        .value("GERMAN", Language::GERMAN)
        .value("HEBREW", Language::HEBREW)
        .value("ITALIAN", Language::ITALIAN)
        .value("JAPANESE", Language::JAPANESE)
        .value("KOREAN", Language::KOREAN)
        .value("NORWEGIAN", Language::NORWEGIAN)
        .value("POLISH", Language::POLISH)
        .value("PORTUGUESE", Language::PORTUGUESE)
        .value("RUSSIAN", Language::RUSSIAN)
        .value("SPANISH", Language::SPANISH)
        .value("SWEDISH", Language::SWEDISH)
        .value("CHINESE", Language::CHINESE)
        .value("CZECH", Language::CZECH)
        .value("GREEK", Language::GREEK)
        .value("ICELANDIC", Language::ICELANDIC)
        .value("LATVIAN", Language::LATVIAN)
        .value("LITHUANIAN", Language::LITHUANIAN)
        .value("ROMANIAN", Language::ROMANIAN)
        .value("HUNGARIAN", Language::HUNGARIAN)
        .value("ESTONIAN", Language::ESTONIAN)
        .value("TG_UNKNOWN_LANGUAGE", Language::TG_UNKNOWN_LANGUAGE)
        .value("UNKNOWN_LANGUAGE", Language::UNKNOWN_LANGUAGE)
        .value("BULGARIAN", Language::BULGARIAN)
        .value("CROATIAN", Language::CROATIAN)
        .value("SERBIAN", Language::SERBIAN)
        .value("IRISH", Language::IRISH)
        .value("GALICIAN", Language::GALICIAN)
        .value("TAGALOG", Language::TAGALOG)
        .value("TURKISH", Language::TURKISH)
        .value("UKRAINIAN", Language::UKRAINIAN)
        .value("HINDI", Language::HINDI)
        .value("MACEDONIAN", Language::MACEDONIAN)
        .value("BENGALI", Language::BENGALI)
        .value("INDONESIAN", Language::INDONESIAN)
        .value("LATIN", Language::LATIN)
        .value("MALAY", Language::MALAY)
        .value("MALAYALAM", Language::MALAYALAM)
        .value("WELSH", Language::WELSH)
        .value("NEPALI", Language::NEPALI)
        .value("TELUGU", Language::TELUGU)
        .value("ALBANIAN", Language::ALBANIAN)
        .value("TAMIL", Language::TAMIL)
        .value("BELARUSIAN", Language::BELARUSIAN)
        .value("JAVANESE", Language::JAVANESE)
        .value("OCCITAN", Language::OCCITAN)
        .value("URDU", Language::URDU)
        .value("BIHARI", Language::BIHARI)
        .value("GUJARATI", Language::GUJARATI)
        .value("THAI", Language::THAI)
        .value("ARABIC", Language::ARABIC)
        .value("CATALAN", Language::CATALAN)
        .value("ESPERANTO", Language::ESPERANTO)
        .value("BASQUE", Language::BASQUE)
        .value("INTERLINGUA", Language::INTERLINGUA)
        .value("KANNADA", Language::KANNADA)
        .value("PUNJABI", Language::PUNJABI)
        .value("SCOTS_GAELIC", Language::SCOTS_GAELIC)
        .value("SWAHILI", Language::SWAHILI)
        .value("SLOVENIAN", Language::SLOVENIAN)
        .value("MARATHI", Language::MARATHI)
        .value("MALTESE", Language::MALTESE)
        .value("VIETNAMESE", Language::VIETNAMESE)
        .value("FRISIAN", Language::FRISIAN)
        .value("SLOVAK", Language::SLOVAK)
        .value("CHINESE_T", Language::CHINESE_T)
        .value("FAROESE", Language::FAROESE)
        .value("SUNDANESE", Language::SUNDANESE)
        .value("UZBEK", Language::UZBEK)
        .value("AMHARIC", Language::AMHARIC)
        .value("AZERBAIJANI", Language::AZERBAIJANI)
        .value("GEORGIAN", Language::GEORGIAN)
        .value("TIGRINYA", Language::TIGRINYA)
        .value("PERSIAN", Language::PERSIAN)
        .value("BOSNIAN", Language::BOSNIAN)
        .value("SINHALESE", Language::SINHALESE)
        .value("NORWEGIAN_N", Language::NORWEGIAN_N)
        .value("PORTUGUESE_P", Language::PORTUGUESE_P)
        .value("PORTUGUESE_B", Language::PORTUGUESE_B)
        .value("XHOSA", Language::XHOSA)
        .value("ZULU", Language::ZULU)
        .value("GUARANI", Language::GUARANI)
        .value("SESOTHO", Language::SESOTHO)
        .value("TURKMEN", Language::TURKMEN)
        .value("KYRGYZ", Language::KYRGYZ)
        .value("BRETON", Language::BRETON)
        .value("TWI", Language::TWI)
        .value("YIDDISH", Language::YIDDISH)
        .value("SERBO_CROATIAN", Language::SERBO_CROATIAN)
        .value("SOMALI", Language::SOMALI)
        .value("UIGHUR", Language::UIGHUR)
        .value("KURDISH", Language::KURDISH)
        .value("MONGOLIAN", Language::MONGOLIAN)
        .value("ARMENIAN", Language::ARMENIAN)
        .value("LAOTHIAN", Language::LAOTHIAN)
        .value("SINDHI", Language::SINDHI)
        .value("RHAETO_ROMANCE", Language::RHAETO_ROMANCE)
        .value("AFRIKAANS", Language::AFRIKAANS)
        .value("LUXEMBOURGISH", Language::LUXEMBOURGISH)
        .value("BURMESE", Language::BURMESE)
        .value("KHMER", Language::KHMER)
        .value("TIBETAN", Language::TIBETAN)
        .value("DHIVEHI", Language::DHIVEHI)
        .value("CHEROKEE", Language::CHEROKEE)
        .value("SYRIAC", Language::SYRIAC)
        .value("LIMBU", Language::LIMBU)
        .value("ORIYA", Language::ORIYA)
        .value("ASSAMESE", Language::ASSAMESE)
        .value("CORSICAN", Language::CORSICAN)
        .value("INTERLINGUE", Language::INTERLINGUE)
        .value("KAZAKH", Language::KAZAKH)
        .value("LINGALA", Language::LINGALA)
        .value("MOLDAVIAN", Language::MOLDAVIAN)
        .value("PASHTO", Language::PASHTO)
        .value("QUECHUA", Language::QUECHUA)
        .value("SHONA", Language::SHONA)
        .value("TAJIK", Language::TAJIK)
        .value("TATAR", Language::TATAR)
        .value("TONGA", Language::TONGA)
        .value("YORUBA", Language::YORUBA)
        .value("CREOLES_AND_PIDGINS_ENGLISH_BASED", Language::CREOLES_AND_PIDGINS_ENGLISH_BASED)
        .value("CREOLES_AND_PIDGINS_FRENCH_BASED", Language::CREOLES_AND_PIDGINS_FRENCH_BASED)
        .value("CREOLES_AND_PIDGINS_PORTUGUESE_BASED", Language::CREOLES_AND_PIDGINS_PORTUGUESE_BASED)
        .value("CREOLES_AND_PIDGINS_OTHER", Language::CREOLES_AND_PIDGINS_OTHER)
        .value("MAORI", Language::MAORI)
        .value("WOLOF", Language::WOLOF)
        .value("ABKHAZIAN", Language::ABKHAZIAN)
        .value("AFAR", Language::AFAR)
        .value("AYMARA", Language::AYMARA)
        .value("BASHKIR", Language::BASHKIR)
        .value("BISLAMA", Language::BISLAMA)
        .value("DZONGKHA", Language::DZONGKHA)
        .value("FIJIAN", Language::FIJIAN)
        .value("GREENLANDIC", Language::GREENLANDIC)
        .value("HAUSA", Language::HAUSA)
        .value("HAITIAN_CREOLE", Language::HAITIAN_CREOLE)
        .value("INUPIAK", Language::INUPIAK)
        .value("INUKTITUT", Language::INUKTITUT)
        .value("KASHMIRI", Language::KASHMIRI)
        .value("KINYARWANDA", Language::KINYARWANDA)
        .value("MALAGASY", Language::MALAGASY)
        .value("NAURU", Language::NAURU)
        .value("OROMO", Language::OROMO)
        .value("RUNDI", Language::RUNDI)
        .value("SAMOAN", Language::SAMOAN)
        .value("SANGO", Language::SANGO)
        .value("SANSKRIT", Language::SANSKRIT)
        .value("SISWANT", Language::SISWANT)
        .value("TSONGA", Language::TSONGA)
        .value("TSWANA", Language::TSWANA)
        .value("VOLAPUK", Language::VOLAPUK)
        .value("ZHUANG", Language::ZHUANG)
        .value("KHASI", Language::KHASI)
        .value("SCOTS", Language::SCOTS)
        .value("GANDA", Language::GANDA)
        .value("MANX", Language::MANX)
        .value("MONTENEGRIN", Language::MONTENEGRIN)
        .value("NUM_LANGUAGES", Language::NUM_LANGUAGES)
        .export_values();

#ifdef VERSION_INFO
    m.attr("__version__") = VERSION_INFO;
#else
    m.attr("__version__") = "dev";
#endif
}
