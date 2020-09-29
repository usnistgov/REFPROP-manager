## 
## Just use docker-compose to spin up this job
##

FROM ubuntu:20.04

RUN apt-get -y -m update && DEBIAN_FRONTEND=noninteractive apt-get install -y cmake python3-numpy g++ gfortran git zip python3-six lcov

# This ADD forces a build (invalidates the cache) if the git repo contents have changed, otherwise leaves it untouched.
# See https://stackoverflow.com/a/39278224
ADD https://api.github.com/repos/usnistgov/REFPROP-cmake/git/refs/heads/master RPcmake-version.json
RUN git clone --recursive https://github.com/usnistgov/REFPROP-cmake

ADD https://api.github.com/repos/usnistgov/REFPROP-manager/git/refs/heads/master RPtests-version.json
RUN git clone --recursive https://github.com/usnistgov/REFPROP-manager 

ADD REFPROP.zip . 

RUN unzip REFPROP.zip -d REFPROP

# Build the special shared library & copy fluid files
WORKDIR /REFPROP-cmake
RUN mkdir build && cd build && \
    cmake .. -DREFPROP_FORTRAN_PATH=/REFPROP/FORTRAN -DCMAKE_BUILD_TYPE=Release -DREFPROP_NO_NUMPY=ON && \
    cmake --build .
WORKDIR /REFPROP-cmake/build
RUN cp -rfv /REFPROP/FLUIDS/ . && cp -rfv /REFPROP/MIXTURES/ .

# Build the testing EXE
WORKDIR /REFPROP-manager
RUN mkdir build && cd build && cmake .. -DCMAKE_BUILD_TYPE=Release && cmake --build .

# Set the environment variables
ENV RPPREFIX /REFPROP-cmake/build
ENV RESOURCES /REFPROP-tests/resources

# Run the exe
WORKDIR /REFPROP-manager/build
CMD ./test2