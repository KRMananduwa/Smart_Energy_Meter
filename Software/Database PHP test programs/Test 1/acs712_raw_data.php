<html>
<body>
<?php
$dbname = 'acs712_raw_data';
$dbuser = 'root';
$dbpass = '';
$dbhost = 'localhost';

$connect = @mysqli_connect($dbhost,$dbuser,$dbpass,$dbname);

if (!$connect){
	echo "Error: " . mysqli_connect_error();
	exit();
}

echo "Connection Succces!<br><br>";
 
$sensorValues = $_GET["sensorValues"];

$query = "INSERT INTO raw_values (data) VALUES ('$sensorValues')";
$result = mysqli_query($connect,$query);

echo "Insertion Succces!<br>";

?>
</body>
</html>