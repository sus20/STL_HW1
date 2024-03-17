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

# Set the range for for x-axis and y-axis
set xrange ["200401":"202001"]
set yrange [-0.7:0]

# Set the delimiter for the data file
set datafile separator ","

# Enable grid
set grid

# Define the first and last points manually
first_x = strptime("%Y%m", "200506")
last_x = strptime("%Y%m", "201811")


# Calculate the corresponding y values
first_y = -0.5448811
last_y = -0.1771908

# Calculate slope and intercept for linear trend line
slope = (last_y - first_y) / (last_x - first_x)
intercept = first_y - slope * first_x

# Define linear trend line function
f(x) = slope * x + intercept

# Plot the data and the trend line
plot 'data.txt' using 2:4 with linespoints pointtype 7 pointsize 1.5 title "Pearson's r", \
     f(x) with lines title "Trend"