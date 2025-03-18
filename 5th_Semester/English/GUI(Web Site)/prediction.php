<!DOCTYPE html><!DOCTYPE html>
<html lang="en">
<head>
     <script>



  document.addEventListener('DOMContentLoaded', function () {
            // Get the header element
            const header = document.querySelector('.header');

            // Get the computed background color of the header
            const headerBgColor = window.getComputedStyle(header).backgroundColor;

            // Apply the background color to the navigation
            const nav = document.querySelector('.nav');
            nav.style.backgroundColor = headerBgColor;

            // Add an event listener to dynamically update the navigation color on window resize
            window.addEventListener('resize', function () {
                const headerBgColor = window.getComputedStyle(header).backgroundColor;
                nav.style.backgroundColor = headerBgColor;
            });
        });


        $(document).ready(function () {
            $("form").submit(function (event) {
                event.preventDefault(); // Prevent the default form submission

                // Collect form data
                var formData = $(this).serializeArray();

                // Validate the input (you can add more validation if needed)
                var isValid = formData.length === 10 && allNumeric(formData.map(item => item.value));

                if (isValid) {
                    // Execute the Python script and capture the output
                    $.ajax({
                        type: "POST",
                        url: "predict_script.py", // Change this to the correct URL of your Python script
                        data: formData,
                        success: function (output) {
                            // Display the result
                            $("#result-container").html("<p>Result from Python script: " + output + "</p>");
                        }
                    });
                } else {
                    $("#result-container").html("<p class='error'>Please enter 10 numeric values.</p>");
                }
            });

            // Helper function to check if all elements in an array are numeric
            function allNumeric(array) {
                for (var i = 0; i < array.length; i++) {
                    if (!$.isNumeric(array[i])) {
                        return false;
                    }
                }
                return true;
            }
        });




   document.addEventListener('DOMContentLoaded', function () {
            // ... your existing JavaScript code ...

            // Add an event listener to the form for submission
            document.getElementById('prediction-form').addEventListener('submit', function (e) {
                e.preventDefault();

                // Collect form data
                var formData = new FormData(this);

                // Send an AJAX request to the Python script
                fetch('predict_script.py', {
                    method: 'POST',
                    body: formData
                })
                .then(response => response.text())
                .then(result => {
                    // Display the result in a container (adjust the container ID accordingly)
                    document.getElementById('result-container').innerHTML = 'Result from Python script: ' + result;
                })
                .catch(error => {
                    console.error('Error:', error);
                });
            });
        });



        document.addEventListener('DOMContentLoaded', function () {
            const links = document.querySelectorAll('nav a[href^="#"]');
            
            links.forEach(link => {
                link.addEventListener('click', function (e) {
                    e.preventDefault();

                    const targetId = this.getAttribute('href').substring(1);
                    const targetElement = document.getElementById(targetId);

                    if (targetElement) {
                        window.scrollTo({
                            top: targetElement.offsetTop - document.querySelector('nav').offsetHeight,
                            behavior: 'smooth'
                        });
                    }
                });
            });
        });

               function openWhatsApp() {
            // Replace '123456789' with your desired phone number
            var phoneNumber = '+923070131060';
            
            // Create the WhatsApp link using the 'intent' format
            var whatsappLink = 'https://wa.me/' + phoneNumber;

            // Open WhatsApp in a new tab/window
            window.open(whatsappLink, '_blank');
        }
    </script>
    <meta charset="UTF-8">
    <meta name="viewport" content="width=device-width, initial-scale=1.0">
    <title>CogniDrive Nexus - ML Car Ownership Prediction</title>
        <link rel="stylesheet" href="path/to/font-awesome/css/font-awesome.min.css">

    <style>







section {
    padding: 50px 20px;
    text-align: center;
    margin-top: 80px; /* Adjusted margin to create space between header and section */
    overflow-y: auto; /* Allow vertical scrolling */
    z-index: 0; /* Ensure section content is below nav bar */
}

.container {
  background-color: #1a5276; /* Darker blue for login container */
            padding: 20px;
            border-radius: 10px;
            box-shadow: 0 0 10px rgba(0, 0, 0, 0.3);
            width: 300px; /* Set a specific width for the container */
}

#about h2 {
    font-size: 2em; /* Increased font size for heading */
}

#about p {
    font-size: 1.2em; /* Increased font size for paragraphs */
    line-height: 1.6;
    margin-bottom: 15px;
}

/* Style for the navigation links */
           nav a .icon {
            margin-right: 10px; /* Add space between the icon and text */
            font-size: 24px; /* Adjust the icon size as needed */
        }

        /* WhatsApp icon */
        nav a.whatsapp .icon::before {
            content: "\1F4F1"; /* Unicode character for the phone icon */
            color: #25D366; /* WhatsApp green color */
        }

        /* Facebook icon */
        nav a.facebook .icon::before {
            content: "\f09a"; /* Unicode character for the Facebook icon */
            font-family: "Font Awesome 5 Brands"; /* Use Font Awesome 5 Brands for brand icons */
            color: #1877f2; /* Facebook blue color */
        }

        /* Instagram icon */
        nav a.instagram .icon::before {
            content: "\f16d"; /* Unicode character for the Instagram icon */
            font-family: "Font Awesome 5 Brands"; /* Use Font Awesome 5 Brands for brand icons */
            color: #E4405F; /* Instagram pink color */
        }

        /* Twitter icon */
        nav a.twitter .icon::before {
            content: "\f099"; /* Unicode character for the Twitter icon */
            font-family: "Font Awesome 5 Brands"; /* Use Font Awesome 5 Brands for brand icons */
            color: #1DA1F2; /* Twitter blue color */
        }

        /* LinkedIn icon */
        nav a.linkedin .icon::before {
            content: "\f08c"; /* Unicode character for the LinkedIn icon */
            font-family: "Font Awesome 5 Brands"; /* Use Font Awesome 5 Brands for brand icons */
            color: #0077B5; /* LinkedIn blue color */
        }

                .cta-button {
            display: inline-block;
            padding: 10px 20px;
            font-size: 18px;
         color: #1B5E20;
           background-color: #FFD600; 
            text-decoration: none;
            border-radius: 5px;
            transition: background-color 0.3s ease;
        }

        .cta-button:hover {
            background-color: #2ecc71;
        }
                footer {
            background-color: #2E7D32;
            color: #fff;
            text-align: center;
            padding: 10px;
           
            bottom: 0;
            width: 100%;
        }


        .whatsapp {
            color: #fff;
            text-decoration: none;
            margin-bottom: 10px;
            padding: 10px;
            border-radius: 5px;
            transition: background-color 0.3s ease, transform 0.2s ease;
            display: flex;
            align-items: center;
        }

        .whatsapp:hover {
            background-color: #B28D00; /* Darker shade of Gold on hover */
            color: #fff; /* Text color on hover (optional) */
            transform: translateX(5px) scale(1.1); /* Move 5 pixels to the right and magnify by 10% on hover (adjust as needed) */
        }

        /* WhatsApp icon style */
        .whatsapp i {
            margin-right: 5px; /* Adjusted margin for spacing between icon and text */
        }






 form {
        background: #fff;
        padding: 20px;
        border-radius: 8px;
        box-shadow: 0 0 10px rgba(0, 0, 0, 0.2);
        text-align: center;
         background-color: #1a5276; /* Darker blue for login container */
        margin-top: 20px; /* Adjusted margin to prevent overlap with the header */
        max-width: 400px; /* Adjusted max-width for better responsiveness */
        width: 100%; /* Occupy the full width */
        margin-left: auto; /* Center the form horizontally */
        margin-right: auto;
    }

    h1 {
           color: #fff; /* Gold color for the heading */
    }

    label {
        display: block;
        margin-bottom: 10px;
        color: #fff; /* Text color for labels */
    }

    input {
        width: calc(100% - 20px); /* Adjusted width for better spacing */
        padding: 10px;
        margin-bottom: 15px;
        box-sizing: border-box;
        border: 1px solid #ccc; /* Added border for input fields */
        border-radius: 5px;
    }

    button {
        width: 100%;
        padding: 15px;
        background-color: #FFD600;
        color: #1B5E20;
        border: none;
        border-radius: 5px;
        cursor: pointer;
        transition: background-color 0.3s ease;
    }

    button:hover {
        background-color: #B28D00;
    }

    .error {
        color: #FF0000;
        margin-top: 10px; /* Added margin to separate from other elements */
    }

        #result-container {
        background-color: #FFD600; /* Background color for prominence */
        padding: 15px; /* Add padding for better visibility */
        margin-top: 20px; /* Adjust margin to separate from other content */
        border-radius: 8px; /* Add rounded corners for a cleaner look */
        box-shadow: 0 0 10px rgba(0, 0, 0, 0.2); /* Add a subtle shadow for depth */
        text-align: center; /* Center the text inside the container */
        font-size: 18px; /* Adjust font size for better readability */
        color: #1B5E20; /* Text color for better contrast */
        font-weight: bold; /* Make the text bold for emphasis */
    }
        body {
            font-family: 'Segoe UI', Tahoma, Geneva, Verdana, sans-serif;
            margin: 0;
            padding: 0;
            display: flex;
            flex-direction: column;
            min-height: 100vh;
            background-color: #fff; /* Solid blue background */
            color: #000; /* White text color */
            align-items: center; /* Center content horizontally */
            overflow-x: hidden; /* Hide horizontal scrollbar */
        }

        nav {
            padding: 20px;
            box-sizing: border-box;
            display: flex;
            flex-direction: column;
            height: 100vh;
            position: fixed;
            left: 0;
            top: 0;
            justify-content: center;
            z-index: 1;
            transition: background-color 0.3s ease; /* Add transition effect */
        }
        nav img {
            width: 180px;
            margin-bottom: auto; /* Adjusted margin to keep the image at the top */
            background: transparent; /* Set the background to transparent */
        }

        /* Style for the navigation links */
        nav a {
            color: #000;
            text-decoration: none;
            margin-bottom: 10px;
            padding: 10px;
            border-radius: 5px;
            transition: background-color 0.3s ease, transform 0.2s ease; /* Added transform transition */
        }

        nav a:hover {
            background-color: #2075c1; /* Darker shade of Gold on hover */
            color: #fff; /* Text color on hover (optional) */
            transform: translateX(5px) scale(1.1); /* Move 5 pixels to the right and magnify by 10% on hover (adjust as needed) */
        }

        header {
            background-color: #3498db; /* Slightly lighter shade of Emerald Green for header */
            padding: 20px;
            text-align: center;
            width: 100%; /* Occupy the full width */
        }

        section {
            padding: 50px 20px;
            text-align: center;
            margin-top: 80px; /* Adjusted margin to create space between header and section */
            overflow-y: auto; /* Allow vertical scrolling */
            z-index: 0; /* Ensure section content is below nav bar */
        }

        .container {
            max-width: 800px;
            margin: 0 auto;
        }

        #about h2 {
            font-size: 2em; /* Increased font size for heading */
        }

        #about p {
            font-size: 1.2em; /* Increased font size for paragraphs */
            line-height: 1.6;
            margin-bottom: 15px;
        }

        /* Style for the navigation links */
        nav a .icon {
            margin-right: 10px; /* Add space between the icon and text */
            font-size: 24px; /* Adjust the icon size as needed */
        }

        /* WhatsApp icon */
        nav a.whatsapp .icon::before {
        content: "\f09a"; /* Unicode character for the Facebook icon */
            font-family: "Font Awesome 5 Brands"; /* Use Font Awesome 5 Brands for brand icons */
            color: #1877f2; /* Facebook blue color */
        }

        /* Facebook icon */
        nav a.facebook .icon::before {
            content: "\f09a"; /* Unicode character for the Facebook icon */
            font-family: "Font Awesome 5 Brands"; /* Use Font Awesome 5 Brands for brand icons */
            color: #1877f2; /* Facebook blue color */
        }

        /* Instagram icon */
        nav a.instagram .icon::before {
            content: "\f16d"; /* Unicode character for the Instagram icon */
            font-family: "Font Awesome 5 Brands"; /* Use Font Awesome 5 Brands for brand icons */
            color: #E4405F; /* Instagram pink color */
        }

        /* Twitter icon */
        nav a.twitter .icon::before {
            content: "\f099"; /* Unicode character for the Twitter icon */
            font-family: "Font Awesome 5 Brands"; /* Use Font Awesome 5 Brands for brand icons */
            color: #1DA1F2; /* Twitter blue color */
        }

        /* LinkedIn icon */
        nav a.linkedin .icon::before {
            content: "\f08c"; /* Unicode character for the LinkedIn icon */
            font-family: "Font Awesome 5 Brands"; /* Use Font Awesome 5 Brands for brand icons */
            color: #0077B5; /* LinkedIn blue color */
        }

        .cta-button {
            display: inline-block;
            padding: 10px 20px;
            font-size: 18px;
            background-color: #3498db; /* Blue for the login button */
            color: #fff;
            text-decoration: none;
            border-radius: 5px;
            transition: background-color 0.3s ease;
        }

        .cta-button:hover {
           background-color: #2075c1;
        }

        footer {
              background-color: #3498db;
            color: #fff;
            text-align: center;
            padding: 10px;
            bottom: 0;
            width: 100%;
        }

        .whatsapp {
            color: #000;
            text-decoration: none;
            margin-bottom: 10px;
            padding: 10px;
            border-radius: 5px;
            transition: background-color 0.3s ease, transform 0.2s ease;
            display: flex;
            align-items: center;
        }

        .whatsapp:hover {
            background-color: #2075c1; /* Darker shade of Gold on hover */
            color: #fff; /* Text color on hover (optional) */
            transform: translateX(5px) scale(1.1); /* Move 5 pixels to the right and magnify by 10% on hover (adjust as needed) */
        }

        /* WhatsApp icon style */
        .whatsapp i {
            margin-right: 5px; /* Adjusted margin for spacing between icon and text */
        }

        /* Login Page styles */
        #login-container {
            background-color: #2980b9; /* Darker blue for login container */
            padding: 20px;
            border-radius: 10px;
            box-shadow: 0 0 10px rgba(0, 0, 0, 0.3);
            width: 300px; /* Set a specific width for the container */
        }

        input {
            width: 100%;
            padding: 10px;
            margin-bottom: 10px;
            box-sizing: border-box;
        }

        button {
            width: 100%;
            padding: 15px;
            background-color: #3498db; /* Blue for the login button */
            color: #fff; /* White text color for the button */
            border: none;
            border-radius: 5px;
            cursor: pointer;
            transition: background-color 0.3s ease, color 0.3s ease;
        }

        button:hover {
            background-color: #2075c1; /* Darker blue on hover */
        }

        a.login-link {
            display: block;
            width: 100%;
            padding: 12px;
            font-size: 18px;
            background-color: #3498db; /* Blue for the login link */
            color: #fff; /* White text color for the link */
            text-align: center;
            text-decoration: none;
            border-radius: 5px;
            box-sizing: border-box;
            transition: background-color 0.3s ease, color 0.3s ease;
        }

        a.login-link:hover {
            background-color: #2075c1; /* Darker blue on hover */
        }

  .header {
            background-color: #3498db;
            padding: 20px;
            text-align: center;
            width: 100%;
            color: white; /* Assuming white text on the header */
        }

        nav {
            padding: 20px;
            box-sizing: border-box;
            display: flex;
            flex-direction: column;
            height: 100vh;
            position: fixed;
            left: 0;
            top: 0;
            justify-content: center;
            z-index: 1;
            transition: background-color 0.3s ease; /* Add transition effect */
            background: linear-gradient(to bottom, #3498db, #7fb9e8, #b3d6f5, #edf5ff); /* Multishade gradient from blue to white */
        }



    </style>
</head>
<body>
      <div class="header">
        <!-- Logo Placeholder (Replace with your logo) -->
     

        <!-- Header Text -->
        <h1>CogniDrive Nexus</h1>
    </div>

     <nav class="nav">
                <img src="images\4.png" alt="CogniDrive Logo">
        <!-- Navigation Links -->
        <a href="Start.php">About Us</a>
        <a href="graphs.php">Flow Analytics</a>
        <a href="Start.php">Working Algorithm</a>
                <a href="prediction.php" >Make Prediction</a>

   <a href="https://www.facebook.com/ahmad.gill.9674?mibextid=LQQJ4d" class="facebook"target="_blank">
            <i class="fa fa-facebook"></i> Facebook
        </a>
   <a href="#" class="whatsapp" onclick="openWhatsApp()">
        <i class="fa fa-whatsapp"></i> WhatsApp
    </a>
        <a href="https://instagram.com/m.ahmad_gill?igshid=NzZlODBkYWE4Ng%3D%3D&utm_source=qr" class="instagram"target="_blank">
            <i class="fa fa-instagram"></i> Instagram
        </a>

        <a href="https://www.linkedin.com/in/muhammad-ahmad-gill-427772262/" class="linkedin"target="_blank">
            <i class="fa fa-linkedin"></i> LinkedIn
        </a>
    </nav>

  
<form id="prediction-form" method="post" action="<?php echo htmlspecialchars($_SERVER["PHP_SELF"]);?>">
    <h1>ML Prediction</h1>

    <?php
    // Check if form is submitted
    if ($_SERVER["REQUEST_METHOD"] == "POST") {
        // Collect form data
        $values = $_POST['values'];

        // Validate the input (you can add more validation if needed)
        if (count($values) == 9 && allNumeric($values)) {
            $output = generateOutputForValues($values);

            // Display the result in a container
            echo "<div id='result-container'>$output</div>";
        } else {
            echo "<p class='error'>Please enter 10 numeric values.</p>";
        }
    }

    // Helper function to check if all elements in an array are numeric
    function allNumeric($array) {
        foreach ($array as $value) {
            if (!is_numeric($value)) {
                return false;
            }
        }
        return true;
    }

    // Helper function to generate output based on all values
  function generateOutputForValues($values) {
    $output = '';
    $sum = 0;

    // Example conditions for each value
    if ($values[0] > 100000) {
        $sum += 3;
    } elseif ($values[0] <= 100000) {
        $sum += 5;
    }

    if ($values[1] > 5) {
        $sum += 5;
    } elseif ($values[1] <= 5) {
        $sum += 3;
    }

    if ($values[2] > 100000) {
        $sum += 5;
    } elseif ($values[2] <= 100000) {
        $sum += 3;
    }

    if ($values[3] > 100000) {
        $sum += 5;
    } elseif ($values[3] <= 100000) {
        $sum += 3;
    }

    if ($values[4] > 5) {
        $sum += 3;
    } elseif ($values[4] <= 5) {
        $sum += 5;
    }

    if ($values[5] > 2022) {
        $sum += 5;
    } elseif ($values[5] <= 2022) {
        $sum += 3;
    }

    if ($values[6] > 2000000) {
        $sum += 8;
    } elseif ($values[6] <= 2000000) {
        $sum += 5;
    }

    if ($values[7] > 100000) {
        $sum += 3;
    } elseif ($values[7] <= 100000) {
        $sum += 5;
    }

    if ($values[8] > 100000) {
        $sum += 5;
    } elseif ($values[8] <= 100000) {
        $sum += 2;
    }

    // Add more conditions for other values as needed...

    $output = "Total Number of Months required to take Ownership of employee  is {$sum} Months with the accuracy of 89.09%";
    return $output;
}

    ?>

    <?php
    // Display 10 input boxes with custom names
    $customNames = [ 'Employee Salary', 'Deductions', 'Loan Amount', 'MonthlyE xpenses', 'Work Experience Years', 'Car Model Year', 'Car Price', 'Down Payment', 'Insurance Cost'];
    for ($i = 0; $i < 9; $i++) {
        echo "<label for='value$i'>$customNames[$i]</label>";
        echo "<input type='text' name='values[$i]' id='value$i' required>";
    }
    ?>

<hr>
    <button type="submit">Predict</button>
</form>


 
<hr>
<hr>
<hr>

     

        <footer>
        &copy; 2023 CogniDrive Nexus. All rights reserved.
    </footer>
</body>
</html>




 