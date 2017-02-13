from distutils.core import setup
from Cython.Build import cythonize

setup(ext_modules = cythonize("ipStochastic.pyx",\
                                sources=["stochasticSum.cpp"],\
                                language="c++",))


# python setup.py build_ext --inplace