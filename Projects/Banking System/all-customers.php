
<!DOCTYPE html>
<html lang="en">
<head>
  <title>Basic Banking System</title>
  <meta charset="utf-8">
  <meta name="viewport" content="width=device-width, initial-scale=1">
  <link rel="stylesheet" href="https://maxcdn.bootstrapcdn.com/bootstrap/3.4.1/css/bootstrap.min.css">
  <script src="https://ajax.googleapis.com/ajax/libs/jquery/3.5.1/jquery.min.js"></script>
  <script src="https://maxcdn.bootstrapcdn.com/bootstrap/3.4.1/js/bootstrap.min.js"></script>

     


  <style>
    body{
    background-color:#008080; 
   
}

    table{
  border-collapse: collapse;
  width: 100%;
  color: white;
  font-family: sans-serif;
  font-size: 20px;
 text-align: left;  
}
th{
background-color:  #FFA07A;
color: white;
}

  </style>


  
</head>

<body>

<nav class="navbar navbar-inverse" style="font-size: 20px;background-color: black;">
  <div class="container-fluid">
    <div class="navbar-header" >
      <a class="navbar-brand" href="index.html" style="color: yellow;">Basic Banking System</a>
    </div>
    <ul class="nav navbar-nav navbar-right">
      <li class="active"><a href="index.html">Home</a></li>
     
      <li><a href="all-customers.php">All Customers</a></li>
            <li><a href="transfer-money.php">Transfer Money</a></li>
                  <li><a href="transfer-list.php">Transfer List</a></li>


    </ul>
    
  </div>
</nav>


<table>
  <tr>
     <center><h1 style="color: white;">Customer Details</h1></center>
      <br><br>
    <th>ID</th>
    <th>Name</th>
    <th>Email</th>
    <th>Amount</th>
  </tr>
  <?php
  $conn = mysqli_connect("localhost", "root", "", "bank");
  if($conn-> connect_error){
  die("Connection failed:". $conn-> connect_error);
}
$sql = "SELECT id,name,email,amount from customers";
$result=$conn-> query($sql);

if($result-> num_rows > 0){
while ($row = $result-> fetch_assoc()){
echo "<tr><td>". $row["id"]."</td><td>". $row["name"]."</td><td>". $row["email"]."</td><td>". $row["amount"]."</td></tr>";

}
echo "</table>";
}
else{
  echo "0 result";
}
$conn-> close();
?>
</table>
  




</body>
</html>
