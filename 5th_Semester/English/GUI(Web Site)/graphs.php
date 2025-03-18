<!DOCTYPE html>
<html lang="en">
<head>
    <meta charset="UTF-8">
    <meta name="viewport" content="width=device-width, initial-scale=1.0">
    <title>Charts Example</title>
    <script src="https://cdn.jsdelivr.net/npm/chart.js"></script>
  <style>
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
        


        

     body {
        font-family: 'Segoe UI', Tahoma, Geneva, Verdana, sans-serif;
        margin: 0;
        padding: 0;
        display: flex;
        flex-direction: column;
        min-height: 100vh;
        background-color: #fff; /* Solid blue background */
        color: #000; /* White text color */
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
        z-index: 2; /* Set a higher z-index to keep the navigation bar on top */
        transition: background-color 0.3s ease; /* Add transition effect */
        background: linear-gradient(to bottom, #3498db, #7fb9e8, #b3d6f5, #edf5ff); /* Multishade gradient from blue to white */
    }

    nav img {
        width: 180px;
        margin-bottom: auto; /* Adjusted margin to keep the image at the top */
        background: transparent; /* Set the background to transparent */
    }

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

    main {
        flex: 1;
        display: flex;
        flex-wrap: wrap;
        justify-content: space-around;
        align-items: flex-start;
        padding: 20px;
        box-sizing: border-box;
        margin-left: 700px;
         margin-right: 920px /* Adjust the margin to accommodate the navigation bar width */
    }

    main div {
        width: 400px;
        margin-bottom: 20px;
        box-sizing: border-box;
        margin-right: 40px; /* Add right margin to create space between charts */
    }
    </style>
</head>
<body>
    <header>
        <!-- Logo Placeholder (Replace with your logo) -->
     

        <!-- Header Text -->
        <h1>CogniDrive Nexus</h1>
    </header>
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
    <main>

     <div style="display: flex; justify-content: space-around; margin-top: 20px;">
            <!-- Chart 1 -->
            <div>
                <h3></h3>
                <canvas id="lineChart" width="400" height="300"></canvas>
<script>
    var ctxLine = document.getElementById('lineChart').getContext('2d');
    var lineChart = new Chart(ctxLine, {
        type: 'line',
        data: {
            labels: ['CEO', 'HR Manager', 'Senior Manager', 'Manager', 'Assistant Manager'],
            datasets: [{
                label: '',
                data: [400000, 350000, 250000, 20000, 10000], // Add a comma after each data point
                borderColor: 'blue',
                borderWidth: 2,
                fill: false
            }]
        }
    });
</script>

        </div>
        <div>
            <h3></h3>
            <canvas id="barChart" width="400" height="300"></canvas>
            <script>
                var ctxBar = document.getElementById('barChart').getContext('2d');
                var barChart = new Chart(ctxBar, {
                    type: 'bar',
                    data: {
                        labels: ['CEO', 'HR Manager', 'Senior Manager', 'Manager', 'Assistant Manager'],
                        datasets: [{
                            label: '',
                            data: [15000, 20000, 15000, 12000, 60000],
                            backgroundColor: 'blue'
                        }]
                    }
                });
            </script>
        </div>
        </div>
         <div style="display: flex; justify-content: space-around; margin-top: 20px;">
            <h3></h3>
            <canvas id="pieChart" width="400" height="300"></canvas>
            <script>
                var ctxPie = document.getElementById('pieChart').getContext('2d');
                var pieChart = new Chart(ctxPie, {
                    type: 'pie',
                    data: {
                        labels: ['2023', '2022', '2021', '2015', '2009'],
                        datasets: [{
                            data: [10, 15, 45, 30, 30],
                            backgroundColor: ['red', 'green', 'blue', 'orange', 'purple']
                        }]
                    }
                });
            </script>
        </div>
    </div>







    <div style="display: flex; justify-content: space-around; margin-top: 20px;">
        <div>
            <h3></h3>
            <canvas id="doughnutChart" width="400" height="300"></canvas>
            <script>
                var ctxDoughnut = document.getElementById('doughnutChart').getContext('2d');
                var doughnutChart = new Chart(ctxDoughnut, {
                    type: 'doughnut',
                    data: {
                        labels: ['Toyota', 'Honda', 'BMW', 'Suzuki', 'KIA'],
                        datasets: [{
                            data: [36, 21, 3, 27, 13],
                            backgroundColor: ['red', 'green', 'blue', 'orange', 'purple']
                        }]
                    }
                });
            </script>
        </div>
        <div>
            <h3></h3>
            <canvas id="radarChart" width="400" height="300"></canvas>
<script>
    var ctxRadar = document.getElementById('radarChart').getContext('2d');
    var radarChart = new Chart(ctxRadar, {
        type: 'radar',
        data: {
            labels: ['CEO', 'HR Manager', 'Senior Manager', 'Manager', 'Assistant Manager'],
            datasets: [{
                label: '',
                data: [10, 30, 45, 15, 25],
                backgroundColor: 'rgba(0, 123, 255, 0.2)',
                borderColor: 'blue',
                borderWidth: 2,
                pointBackgroundColor: 'blue', // Highlight the points
                pointBorderColor: 'blue', // Highlight the point borders
                pointRadius: 5, // Set the radius of the points
            }]
        }
    });
</script>
        </div>
    </div>

</main>
</body>
</html>
