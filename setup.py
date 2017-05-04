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

# setup(ext_modules = cythonize(Extension("ipTreeGMPExtended",\
#            sources=["ipTreeGMPExtended.pyx", "generalizedStochasticGMPExtended.cpp"],\
#            include_dirs = ["/usr/local/include"],\
#            libraries = ["gmpxx","gmp"],\
#            library_dirs = ["/usr/local/lib"],\
#            language = "c++",\
#            extra_compile_args=["-std=c++11"],\
#       )))


setup(ext_modules = cythonize(Extension("ipNEW",\
           sources=["ipNEW.pyx", "./src/logProbIPNew.cpp",\
                                 "./src/helperFunctions.cpp",\
                                 "./src/uniformMonteCarloIntegration.cpp",\
                                 "./src/pdfSamplingMonteCarloIntegration.cpp",\
                                 "./src/bruteForceMonteCarloIntegration.cpp",\
                                 "./src/hybridMonteCarloIntegration.cpp",\
                                 "./src/BMIP.cpp"],\
           include_dirs = ["/usr/local/include","./src"],\
           libraries = ["gsl","gslcblas"],\
           library_dirs = ["/usr/local/lib"],\
           language = "c++",\
           extra_compile_args=["-std=c++11"]\
      )))

# python setup.py build_ext --inplace

# g++ -I /usr/local/include -L/usr/local/lib generalizedStochasticGMP.cpp -lgmpxx -lgmp -std=c++11
