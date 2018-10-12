<?php
$host = "localhost";

$username = "root";

$password = "";

$database = "IRVALUES";

$connect = mysqli_connect($host, $username, $password, $database);
$usid1=$_GET['value1'];
$usid2=$_GET['value2'];
$usid3=$_GET['value3'];
$usid4=$_GET['value4'];
$usid5=$_GET['value5'];
$usid6=$_GET['value6'];
$usid7=$_GET['value7'];
$usid8=$_GET['value8'];
$usid9=$_GET['value9'];
$usid10=$_GET['value10'];
$usid11=$_GET['value11'];
#$usid12=$_GET['value12'];


// Create connection
//$conn = new mysqli($servername, $username,$password, $dbname);
// Check connection
//if ($conn->connect_error) {
  //  die("Connection failed: " . $conn->connect_error);
//} 
//$val = $_GET['value'];
$sql = "INSERT INTO IRVALUES(IRVALUE1,IRVALUE2,IRVALUE3,IRVALUE4,IRVALUE5,IRVALUE6,IRVALUE7,IRVALUE8,IRVALUE9,IRVALUE10,IRVALUE11) VALUES ('$usid1','$usid2','$usid3','$usid4','$usid5','$usid6','$usid7','$usid8','$usid9','$usid10','$usid11');";
//mysql_query($sql,$conn);
mysqli_query($connect, $sql);

//if ($conn->query($sql) === TRUE) {
  //  echo "ir value inserted Successfully!";
//} else {
  //  echo "Error:" . $sql . "<br>" . $conn->error;
//}

$connect->close();
?>
