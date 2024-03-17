# Set terminal and output
set terminal pdfcairo enhanced color solid font "Arial, 12"
set output 'plot.pdf'

# Set titles and labels
set xlabel "Year"
set ylabel "Coefficient (ρ)"

# Set the format for x-axis
set xdata time
set timefmt "%Y%m"
set format x "%Y"

# Set the range for y-axis
set yrange [-0.7:0]

# Set the delimiter for the data file
set datafile separator ","

# Enable grid
set grid

# Fit a linear model to the data
f(x) = a*x + b
fit f(x) 'data.txt' using 2:4 via a, b

# Plot the data
plot 'data.txt' using 2:4 with linespoints pointtype 7 pointsize 1.5 title "Pearson's r", \
     f(x) with lines title "Trend"