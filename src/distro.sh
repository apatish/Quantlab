#!/usr/bin/env /bin/bash
export PATH=$PATH:/usr/local/bin:/home/$USER/bin:/usr/lib64/qt-3.3/bin:/usr/local/bin:/bin:/usr/bin:/usr/local/sbin:/usr/sbin:/sbin
source /opt/rh/devtoolset-6/enable
rm CMakeCache.txt
/home/$USER/bin/cmake -GNinja -DCMAKE_VERBOSE_MAKEFILE=ON -DAPPTYPE=BOPS -DCMAKE_SYSTEM_NAME=Linux -DCMAKE_BUILD_TYPE=Debug -DCMAKE_MAKE_PROGRAM=/home/$USER/bin/ninja -DCMAKE_CXX_COMPILER_LAUNCHER=/home/$USER/bin/ccache -DCMAKE_SOURCE_DIR=./src || exit 1
/home/$USER/bin/ninja $TARGET || exit 1
