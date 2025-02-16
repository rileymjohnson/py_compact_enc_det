from pybind11.setup_helpers import Pybind11Extension, build_ext
from setuptools import setup

__version__ = "0.0.1"

ext_modules = [
    Pybind11Extension(
        "py_compact_enc_det",
        [
            'compact_enc_det/compact_enc_det/compact_enc_det.cc',
            'compact_enc_det/compact_enc_det/compact_enc_det_hint_code.cc',
            'compact_enc_det/util/encodings/encodings.cc',
            'compact_enc_det/util/languages/languages.cc',
            'module.cc'
        ],
        define_macros=[("VERSION_INFO", f'"{__version__}"')],
        include_dirs=["compact_enc_det"]
    ),
]

setup(
    name="py_compact_enc_det",
    version=__version__,
    author="Riley Johnson",
    author_email="rileymillerjohnson@gmail.com",
    url="https://github.com/rileymjohnson/py_compact_enc_det",
    description="Python bindings for compact_enc_det",
    long_description="",
    ext_modules=ext_modules,
    cmdclass={"build_ext": build_ext},
    zip_safe=False,
    python_requires=">=3.11",
)