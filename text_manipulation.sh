#!/bin/bash

# Step 1: Create the sample employee data file
cat <<EOF > employees.txt
Alice HR 55000
Bob IT 70000
Charlie Finance 65000
David IT 72000
Eve HR 58000
Frank Finance 67000
Grace IT 73000
Hank HR 56000
EOF

# Step 2: Process the file using grep, awk, tr, sort, and sed
grep " IT " employees.txt |  # Extract IT department employees
awk '{print $1, $2, $3}' |   # Extract name, department, and salary
tr '[:lower:]' '[:upper:]' | # Convert names to uppercase
sort -k3,3nr |               # Sort by salary (descending)
sed 's/ / (/;s/ /): /'       # Format output as "NAME (DEPARTMENT): SALARY"
