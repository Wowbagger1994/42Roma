<?php
echo "<br><br> COOKIE: <br>";
var_dump($_COOKIE);
echo "<br><br> GET: <br>";
var_dump($_GET);
echo "<br><br> POST: <br>";
var_dump($_POST);
echo "<br><br> FILES: <br>";
var_dump($_FILES);
echo "<br>";
echo "<br>";
echo "";

if (isset($_POST['lname']))
{
    echo "Last name " . $_POST['lname'];
}
    echo "<br>";
if (isset($_POST['fname']))
{
    echo "First name " . $_POST['fname'];
}

echo "<br>";
if(isset($_POST['lname']) && isset($_POST['fname']) && $_POST['fname'] != '' && $_POST['lname'] != '')
{
  setcookie("lname", $_POST['lname'], time() + (86400 * 30), "/");
  setcookie("fname", $_POST['fname'], time() + (86400 * 30), "/"); // 86400 = 1 day
  echo  "<br><a href='./cookie.php'>see cookie</a>";
}
// Check if image file is a actual image or fake imag<e
if (isset($_FILES["image"]))
{
  $image_file = $_FILES["image"];
}

// Image not defined, let's exit
if (isset($image_file)) {

  echo '<pre>';
  if (getenv("UPLOAD_PATH") == "")
  {
    echo "upload not allowed\n";
    die(1);
  }
    echo "#";
    echo (getenv("UPLOAD_PATH"));
    echo "\n";
    if ($_FILES["image"]["size"] > 0 )
    {
    // Move the temp image file to the images/ directory
    if(!file_exists(getenv("UPLOAD_PATH")))
      mkdir(getenv("UPLOAD_PATH"));

    if (move_uploaded_file($image_file["tmp_name"], getenv("UPLOAD_PATH") . $image_file["name"])) {
        echo "\nFile is valid, and was successfully uploaded.\n";
        echo  "<br><a href='/uploads/'>look new file</a>";
    } else {
        echo "Possible file upload attack!\n";
    }

    print "</pre>";
    }
}




?>
