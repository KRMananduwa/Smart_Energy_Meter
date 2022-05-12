<?php

session_start();
if(!isset($_SESSION['username'])){
    header('location:login.php');
}
?>

<html>
<head>
    <meta charset="UTF-8">
    <title> Home Page </title>
    <link rel="stylesheet" href="homestyle.css">
</head>
<body>
    <header>
        <div class="wrapper">
            <div class="logo">
                <img src="images/logo.png" alt="">
            </div>
            <ul class="nav-area">
                <li><a href="#">Home</a></li>
                <li><a href="#">About</a></li>
                <li><a href="data.php">Data</a></li>
                <li><a href="#">Products</a></li>
                <li><a href="#">Contact</a></li>
            </ul>
        </div>
        <div class="welcome-text">
            <h1> Welcome <?php echo $_SESSION['username']; ?> </h1>
            <a href="logout.php"> LOGOUT </a>
        </div>
    </header>

</body>
</html>