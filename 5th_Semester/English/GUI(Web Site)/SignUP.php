<!DOCTYPE html>
<html lang="en">
<head>
    <meta charset="UTF-8">
    <meta name="viewport" content="width=device-width, initial-scale=1.0">
    <title>Signup Page</title>
    <style>
        body {
            font-family: 'Segoe UI', Tahoma, Geneva, Verdana, sans-serif;
            margin: 0;
            padding: 0;
            background-color : #fff;/* Emerald Green to Gold gradient */
            color: #fff;
            display: flex;
            align-items: center;
            justify-content: center;
            height: 100vh;
        }

        #signup-container {
            background-color:#1a5276; /* Darker shade of Emerald Green for signup container */
            padding: 20px;
            border-radius: 10px;
            box-shadow: 0 0 10px rgba(0, 0, 0, 0.3);
        }

        input {
            width: 100%;
            padding: 10px;
            margin-bottom: 10px;
            box-sizing: border-box;
        }

        button {
            width: 100%;
            padding: 10px;
            background-color: #3498db; /* Gold for the signup button */
            color: #fff; /* Darker shade of Emerald Green for text color */
            border: none;
            border-radius: 5px;
            cursor: pointer;
            transition: background-color 0.3s ease;
        }

        button:hover {
            background-color: #2075c1; /* Darker shade of Gold on hover */
        }

        a.login-link {
            display: block;
            width: 100%;
            padding: 12px; /* Adjusted padding */
            font-size: 18px; /* Adjusted font size */
                      background-color: #3498db; /* Gold for the signup button */
            color: #fff;
            text-align: center;
            text-decoration: none;
            border-radius: 5px;
            box-sizing: border-box; /* Include padding and border in the total width and height */
            transition: background-color 0.3s ease;
        }

        a.login-link:hover {
            background-color: #2075c1; /* Darker blue on hover */
        }
    </style>
</head>
<body>
    <div id="signup-container">
        <h2>Sign Up</h2>
        <form action="signup_process.php" method="post">
            <input type="text" name="username" placeholder="Username" required>
            <input type="password" name="password" placeholder="Password" required>
            <input type="password" name="confirm_password" placeholder="Confirm Password" required>
          <a href="Start.php" class="login-link">Sign Up</a>
        </form>
        <p>Already have an account? <a href="log_in.php" class="login-link">Login</a></p>
    </div>
</body>
</html>
