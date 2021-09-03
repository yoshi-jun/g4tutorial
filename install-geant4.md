# Geant4 install for Ubuntu 

install for cmake 

~~~
sudo apt-get install libexpat1-dev
sudo apt-get install libxerces-c-dev
~~~

cmake
~~~
$ cmake -DCMAKE_INSTALL_PREFIX=/opt/geant4/10.07.p02/ -DGEANT4_USE_OPENGL_X11=ON -DGEANT4_USE_QT=ON -DGEANT4_USE_RAYTRACER_X11=ON -DGEANT4_USE_GDML=ON -DGEANT4_INSTALL_DATADIR= /opt/geant4/src/geant4.10.07.p02/
$ make -j20
$ make install
~~~

~~~
$ cmake -DCMAKE_INSTALL_PREFIX=/opt/geant4/10.07.p02-mt/ -DGEANT4_USE_GDML=ON -DGEANT4_INSTALL_DATADIR=/opt/geant4/data/10.07.p02/ -DGEANT4_BUILD_MULTITHREADED=ON -DGEANT4_INSTALL_DATADIR= /opt/geant4/src/geant4.10.07.p02/
$ make -j20
$ make install
~~~

installed

ver 10.5.1 & 10.6.3 installed 
~~~
$ ls /opt/geant4/
10.05.p01     10.06.p03     10.07.p02     build  src
10.05.p01-mt  10.06.p03-mt  10.07.p02-mt  data
~~~
