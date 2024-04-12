#!/bin/bash

# Prompt the user to enter the number of files to create
read -p "Enter the number of files to create: " num_files

# Create a directory named "binary_files" on the desktop
mkdir -p ~/Desktop/binary_files

# Store the path of the directory where files are created
output_dir=~/Desktop/binary_files

# Loop to create the specified number of files
for ((i = 1; i <= num_files; i++)); do
    # Generate random binary code (100 lines of 0s and 1s)
    for ((j = 1; j <= 100; j++)); do
        # Generate a random binary string of length 50
        binary_string=""
        for ((k = 1; k <= 50; k++)); do
            binary_string+=$((RANDOM % 2))
        done
        echo $binary_string >> $output_dir/file_$i.txt
    done
done

echo "Files created successfully on the desktop."

# Print the contents of the directory where binary files are created
echo "Contents of $output_dir:"
ls -la $output_dir

# Prompt the user if they want to see the files
read -p "Do you want to see the files created? (y/n): " view_files

if [ "$view_files" == "y" ]; then
    echo "Contents of $output_dir/file_1.txt:"
    cat $output_dir/file_1.txt
fi

# Prompt the user if they want to delete the created files
read -p "Do you want to delete the created binary files? (y/n): " delete_files

if [ "$delete_files" == "y" ]; then
    rm -rf $output_dir
    echo "Files deleted successfully."
fi

