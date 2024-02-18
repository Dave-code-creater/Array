import random

# Define the range of numbers for the file names
file_range = range(1, 11)

# Define the range of numbers for the array elements
element_range = range(-100, 101)

# Define the maximum number of elements in the array
max_elements = 10

# Loop through the file range
for i in file_range:
  # Generate a random number of elements
  num_elements = random.randint(1, max_elements)
  # Generate a random array of elements
  array = random.sample(element_range, num_elements)
  # Create the file name
  file_name = f"test/test_case_{i}.txt"
  # Open the file in write mode
  with open(file_name, "w") as f:
    # Write the number of elements to the first line
    f.write(f"{num_elements}\n")
    # Write the array elements to the second line, separated by spaces
    f.write(" ".join(map(str, array)) + "\n")