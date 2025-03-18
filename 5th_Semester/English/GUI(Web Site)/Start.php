<!DOCTYPE html>
<html lang="en">
<head>
     <script>
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
            /* Use the image as the background */
              background-color: #3498db;
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
    <header>
        <!-- Logo Placeholder (Replace with your logo) -->
     

        <!-- Header Text -->
        <h1>CogniDrive Nexus</h1>
    </header>

    <nav>
                <img src="images\4.png" alt="CogniDrive Logo">
        <!-- Navigation Links -->
        <a href="#about">About Us</a>
        <a href="graphs.php">Flow Analytics</a>
        <a href="#algorithm">Working Algorithm</a>
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

 <section id="about" class="container">
    <h2>About Us</h2>
    <p>CogniDrive Nexus is a pioneering force in the realm of technological innovation, specializing in the development and application of cutting-edge solutions in Machine Learning, Data Science, and Artificial Intelligence. As a company, we are driven by a commitment to excellence, a passion for pushing technological boundaries, and a vision for a smarter and more connected future.</p>

    <p>Our suite of products revolves around harnessing the power of AI and ML to transform the landscape of corporate fleet management. From predictive analytics to data-driven decision-making, we empower organizations to optimize their car ownership processes and make informed choices.</p>

    <p>At CogniDrive Nexus, we aim to bridge the gap between technology and real-world challenges. Our dedicated team of professionals brings together expertise, creativity, and a shared ambition to make a lasting impact. By fostering innovation and embracing the possibilities of emerging technologies, we strive to shape a future where intelligent solutions drive positive change.</p>
</section>

<section id="algorithm" class="container">
    <h2>Working Algorithm</h2>
    <p>CogniDrive Nexus employs a sophisticated Machine Learning (ML) approach coupled with the power of Artificial Intelligence (AI) in the development of its predictive regression model.</p>

    <p>The algorithm utilizes diverse features such as demographics and socioeconomic status, collected and pre-processed meticulously. The dataset is then split into training and testing sets, and feature engineering techniques are applied to enhance model performance.</p>

    <p>Through optimization, evaluation, and interpretation of the chosen regression algorithm, the model provides valuable insights into the nuanced decision-making process of car ownership. It aims to empower users with the ability to make informed choices, and optionally, the model can be deployed for real-world predictions. Thorough documentation accompanies the project, ensuring transparency and ease of replication.</p>
</section>
        <section>
              <p>ML-Based Corporate Car Ownership Threshold Prediction</p>
        <h2>Welcome to the Future of Corporate Fleet Management!</h2>
        <p>Unlock the power of machine learning to optimize your corporate car ownership decisions.</p>
        <a href="prediction.php" class="cta-button">Get Started</a>
    </section>

<hr>
<hr>
<hr>

        <footer>
        &copy; 2023 CogniDrive Nexus. All rights reserved.
    </footer>
</body>
</html>
