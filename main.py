import pandas as pd
import numpy as np

# Number of entries
num_entries = 100000

metrics = ['Total Tasks', 'Task Completion Rate', 'Error Rate', 'Attendance']

# Generate random data
data = {metric: np.random.randint(1, 10, num_entries) for metric in metrics}
df = pd.DataFrame(data)

# Add the unique IDs to the DataFrame as the first column
df.insert(0, 'ID', range(1, num_entries + 1))

# Normalize the data to a scale of 0 to 100
for metric in metrics:
    df[metric] *= 10

# Weights
weights = {
    'Total Tasks': 0.30,
    'Task Completion Rate': 0.30,
    'Error Rate': 0.20,  
    'Attendance': 0.20
}

# Calculate Productivity Score
df['Productivity Score'] = (df['Total Tasks'] * weights['Total Tasks'] +
                            df['Task Completion Rate'] * weights['Task Completion Rate'] +
                            df['Error Rate'] * weights['Error Rate'] +
                            df['Attendance'] * weights['Attendance'])

# Convert Productivity Score to integer
df['Productivity Score'] = df['Productivity Score'].astype(int)

# Export to CSV
df.to_csv('employee_performance_data.csv', index=False)
