
printf "Making directory Orig_CoMD \n"
mkdir Orig_CoMD
cd Orig_CoMD/
git init
git clone https://github.com/exmatex/CoMD.git
cd CoMD/
cd src-mpi/
cp Makefile.vanilla Makefile


cd ..
cd ..
cd ..
mkdir Pruitt_CoMD
cd Pruitt_CoMD/
git init
git clone https://github.com/daviddpruitt/CoMD.git
cd CoMD/
cp Makefile.vanilla Makefile
cd ..
ls
pwd

printf "Dont forget to load the module\n"
printf "HINT:  module load mpi/openmpi-x86_64 \n"