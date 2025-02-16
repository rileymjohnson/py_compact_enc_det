from setuptools import setup, Extension
import pybind11

sfc_module = Extension(
    'py_compact_enc_det',
    sources=['module.cc'],
    include_dirs=[pybind11.get_include()],
    language='c++',
)

setup(
    name='py_compact_enc_det',
    version='1.0',
    description='compact_enc_det bindings for python',
    ext_modules=[sfc_module],
)