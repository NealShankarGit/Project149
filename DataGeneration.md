
Data Generation Code Documentation

Purpose of the Script:
This script is designed to generate a dataset of employee performance metrics and calculate a Productivity Score for each employee based on weighted criteria.

Functionality:
Generates random data for various performance metrics.
Normalizes and processes the data as per the requirements.
Calculates a Productivity Score for each employee using a weighted formula.
Exports the data to a CSV file.
 
Code Breakdown:
Importing Libraries
pandas: Used for data manipulation and analysis.
numpy: Used for numerical operations.
Code:
import pandas as pd import numpy as np
Setting Up Data Generation
num_entries: Defines the number of data entries (employees) to generate.
metrics: A list of performance metrics.
Code:
num_entries = 100000 metrics = ['Total Tasks', 'Task Completion Rate', 'Error Rate', 'Attendance']
Generating Random Data
Random data for each metric is generated using numpy.
Data is stored in a dictionary and then converted into a DataFrame.
Code:
 
data = {metric: np.random.randint(1, 10, num_entries) for metric in metrics} df = pd.DataFrame(data)
Adding Unique IDs
A unique ID is assigned to each entry, serving as an identifier for each employee.
Code:
 
df.insert(0, 'ID', range(1, num_entries + 1))
Normalizing Data
Each metric is normalized to a scale of 0 to 100.
Code:
 
for metric in metrics: df[metric] *= 10
Defining Weights for Each Metric
Weights are assigned to each metric based on their importance in calculating the Productivity Score.
Code:
 
weights = { 'Total Tasks': 0.30, 'Task Completion Rate': 0.30, 'Error Rate': 0.20, 'Attendance': 0.20 }
Calculating Productivity Score
The Productivity Score is calculated using the weighted sum of the metrics.
The score is then converted to an integer for simplicity.
Code:
 
df['Productivity Score'] = (df['Total Tasks'] * weights['Total Tasks'] + df['Task Completion Rate'] * weights['Task Completion Rate'] + df['Error Rate'] * weights['Error Rate'] + df['Attendance'] * weights['Attendance']) df['Productivity Score'] = df['Productivity Score'].astype(int)
Exporting Data to CSV
The final DataFrame is exported to a CSV file, which can be used for further analysis or reporting.
Code:
 
df.to_csv('employee_performance_data.csv', index=False)
Usage:
Run the script to generate the dataset.
The CSV file named 'employee_performance_data.csv' will be created in the script's directory.
This file contains the employee IDs, their performance metrics, and the calculated Productivity Scores.




Menu Code Documentation:

This C++ program manages employee performance data from a CSV file (employee_performance_data.csv). It provides functionalities to search for an employee by ID and to find the bottom performer based on productivity score using a min-heap.

Key Data Structures
Employee Struct: Holds individual employee data.
Hash Map (employeeMap): Facilitates fast search by employee ID.
Min-Heap (employeeHeap): Helps quickly find the employee with the lowest productivity score.

Core Functions
readCSV: Reads and parses the CSV file, populating the hash map and min-heap.
searchById: Searches for an employee by ID.
findBottomPerformer: Finds the employee with the lowest productivity score.
displayEmployee: Displays an employee's details.
main: Handles the user interface and menu logic.
