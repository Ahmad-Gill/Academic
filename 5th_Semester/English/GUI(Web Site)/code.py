# code.py

import pandas as pd
from sklearn.model_selection import train_test_split
from sklearn.ensemble import RandomForestRegressor
import sys

def main():
    try:
        # Get 9 numeric values from command-line arguments (assuming you mentioned 9 values)
        input_values = [float(arg) for arg in sys.argv[1:]]

        # Load CSV file
        csv_file = "VERSION#0.2.csv"
        data = load_csv(csv_file)

        if data is not None:
            # Split the data into features and labels
            X = data.iloc[:, 1:]  # Assuming the features are in columns 1 and onwards
            y = data.iloc[:, 0]   # Assuming the label is in the first column

            # Split the data into training and testing sets
            X_train, X_test, y_train, y_test = train_test_split(X, y, test_size=0.2, random_state=42)

            # Train a RandomForestRegressor (you can use a different model based on your needs)
            model = RandomForestRegressor()
            model.fit(X_train, y_train)

            # Use the trained model to predict the output based on user input
            prediction = model.predict([input_values])

            # Print the prediction
            print(f"Prediction: {prediction[0]}")
        else:
            print("Error: Unable to load CSV file.")
    except ValueError:
        # Handle the case where a non-numeric value is provided
        print("Error: Please provide 9 numeric values.")

def load_csv(file):
    try:
        # Load CSV file using pandas
        df = pd.read_csv(file)
        return df
    except Exception as e:
        print(f"Error loading CSV file: {e}")
        return None

if __name__ == "__main__":
    main()
