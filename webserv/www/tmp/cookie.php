<html>
<body>

<?php
if (isset($_GET["si"]) && isset($_COOKIE["lname"]) && isset($_COOKIE["fname"]))
{
  unset($_COOKIE["lname"]);
  unset($_COOKIE["fname"]);
  setcookie("lname", "", -1, '/');
  setcookie("fname", "", -1, '/');
}
if(isset($_COOKIE["lname"]) && isset($_COOKIE["fname"])) {

  echo "<center><br><br><br><h1>Welcome " . $_COOKIE["lname"] . " " . $_COOKIE["fname"]. "</h1></center>";

  echo  "<center><br><a href='./post_test.php?si=1'>log out</a></center>";
} else {
  echo "<center><br><br><br><h1>Cookie not set!</h1></center>";
  echo "<center><br><a href='./post_test.php'>login</a></center>";
}

?>

</body>
</html>
