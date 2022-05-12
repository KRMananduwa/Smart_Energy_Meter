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
                <li><a href="#">Data</a></li>
                <li><a href="#">Products</a></li>
                <li><a href="#">Contact</a></li>
            </ul>
        </div>
        <div class="welcome-text">
            <h1> Welcome <?php echo $_SESSION['username']; ?> </h1>
            <a href="logout.php"> LOGOUT </a>
        </div>

        <?php

// session_start();

$con = mysqli_connect('localhost','root','');

mysqli_select_db($con, 'energyuse');


$s = "select * from smartmeter";

$result = mysqli_query($con, $s);


echo '
    <table>
        <thead>
            <tr>
                <th>ID</th>
                <th>CREATED ON</th>
                <th>kWh</th>
                <th>Wh</th>
                <th>Amps(TRMS)</th>
            </tr>
        </thead>
        <tbody>';
while($row = mysqli_fetch_array($result)) {
    echo '<tr>';
    echo '<td>'.$row['id'].'</td>';
    echo '<td>'.$row['created_at'].'</td>';
    echo '<td>'.$row['kWh'].'</td>';
    echo '<td>'.$row['Wh'].'</td>';
    echo '<td>'.$row['Amps_TRMS'].'</td>';
    echo '</tr>';
}
echo '
        </tbody>
    </table>';

?>
    </header>

</body>
</html>