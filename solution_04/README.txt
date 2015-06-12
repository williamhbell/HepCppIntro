This file can be built into an executable by typing:

cd src/; make

The executable can then be run by typing

./Histogram.exe

The program writes a single histogram into the file data.hst.  These data can then be plotted 
with gnuplot via

../bin/plot.sh data.hst

