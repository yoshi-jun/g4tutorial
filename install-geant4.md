# Geant4 install for Ubuntu 

## cmake&make 
~~~
$ cmake -DCMAKE_INSTALL_PREFIX=/opt/geant4/10.07.p02/ -DGEANT4_USE_OPENGL_X11=ON -DGEANT4_USE_QT=ON -DGEANT4_USE_RAYTRACER_X11=ON -DGEANT4_USE_GDML=ON -DGEANT4_INSTALL_DATA=ON -DGEANT4_INSTALL_DATADIR= /opt/geant4/src/geant4.10.07.p02/
$ make -j20
$ make install
~~~

~~~
$ cmake -DCMAKE_INSTALL_PREFIX=/opt/geant4/10.07.p02-mt/ -DGEANT4_USE_GDML=ON -DGEANT4_INSTALL_DATADIR=/opt/geant4/data/10.07.p02/ -DGEANT4_BUILD_MULTITHREADED=ON -DGEANT4_INSTALL_DATADIR= /opt/geant4/src/geant4.10.07.p02/
$ make -j20
$ make install
~~~

## structure of directory
~~~
$ ls /opt/geant4/
10.05.p01     10.06.p03     10.07.p02     build  src
10.05.p01-mt  10.06.p03-mt  10.07.p02-mt  data
~~~

## check geant4 datasets 
~~~
$ geant4-config --check-datasets
G4NDL INSTALLED /opt/geant4/10.07.p02/share/Geant4-10.7.2/data/G4NDL4.6
G4EMLOW INSTALLED /opt/geant4/10.07.p02/share/Geant4-10.7.2/data/G4EMLOW7.13
PhotonEvaporation INSTALLED /opt/geant4/10.07.p02/share/Geant4-10.7.2/data/PhotonEvaporation5.7
RadioactiveDecay INSTALLED /opt/geant4/10.07.p02/share/Geant4-10.7.2/data/RadioactiveDecay5.6
G4PARTICLEXS INSTALLED /opt/geant4/10.07.p02/share/Geant4-10.7.2/data/G4PARTICLEXS3.1.1
G4PII INSTALLED /opt/geant4/10.07.p02/share/Geant4-10.7.2/data/G4PII1.3
RealSurface INSTALLED /opt/geant4/10.07.p02/share/Geant4-10.7.2/data/RealSurface2.2
G4SAIDDATA INSTALLED /opt/geant4/10.07.p02/share/Geant4-10.7.2/data/G4SAIDDATA2.0
G4ABLA INSTALLED /opt/geant4/10.07.p02/share/Geant4-10.7.2/data/G4ABLA3.1
G4INCL INSTALLED /opt/geant4/10.07.p02/share/Geant4-10.7.2/data/G4INCL1.0
G4ENSDFSTATE INSTALLED /opt/geant4/10.07.p02/share/Geant4-10.7.2/data/G4ENSDFSTATE2.3

~~~
