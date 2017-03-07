from distutils.core import setup, Extension
from Cython.Build import cythonize

# setup(ext_modules = cythonize(Extension(\
#            "ipStochastic",\
#            sources=["ipStochastic.pyx", "stochasticSum.cpp"],\
#            language="c++",\
#            extra_compile_args=["-std=c++11"],\
#            extra_link_args=["-std=c++11"]\
#       )))

# setup(ext_modules = cythonize(Extension(\
#            "ipTreeStochastic",\
#            sources=["ipTreeStochastic.pyx", "treeStochasticSum.cpp"],\
#            language="c++",\
#            extra_compile_args=["-std=c++11"],\
#            extra_link_args=["-std=c++11"]\
#       )))


# setup(ext_modules = cythonize(Extension(\
#            "ipTree",\
#            sources=["ipTree.pyx", "generalizedStochastic.cpp"],\
#            language="c++",\
#            extra_compile_args=["-std=c++11"],\
#            extra_link_args=["-lgmpxx","-lgmp"]\
#       )))

setup(ext_modules = cythonize(Extension(\
           "ipTree",\
           sources=["ipTree.pyx", "generalizedStochastic.cpp"],\
           language="c++",\
           extra_compile_args=["-std=c++11","-lgmpxx","-lgmp"]
      )))

# python setup.py build_ext --inplace