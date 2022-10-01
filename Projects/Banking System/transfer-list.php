<?php
$db=new PDO('mysql:host=localhost;dbname=bank','root','');

?>


<!DOCTYPE html>
<html lang="en">
<head>
  <title>Basic Banking System</title>
  <meta charset="utf-8">
  <meta name="viewport" content="width=device-width, initial-scale=1">
  <link rel="stylesheet" href="https://maxcdn.bootstrapcdn.com/bootstrap/3.4.1/css/bootstrap.min.css">
  <script src="https://ajax.googleapis.com/ajax/libs/jquery/3.5.1/jquery.min.js"></script>
  <script src="https://maxcdn.bootstrapcdn.com/bootstrap/3.4.1/js/bootstrap.min.js"></script>

<style >
      body{
      background-color: #008080;
    }


td{
      width: 200px;
      height: 50px;
    }

   



</style>
  

  
</head>

<body>

<nav class="navbar navbar-inverse" style="font-size: 20px;background-color: black;">
  <div class="container-fluid">
    <div class="navbar-header" >
      <a class="navbar-brand" href="#" style="color: yellow;">Basic Banking System</a>
    </div>
    <ul class="nav navbar-nav navbar-right">
      <li class="active"><a href="index.html">Home</a></li>
     
      <li><a href="all-customers.php">All Customers</a></li>
            <li><a href="transfer-money.php">Transfer Money</a></li>
                  <li><a href="transfer-list.php">Transfer List</a></li>


    </ul>
    
  </div>
</nav>

  






   
   
      <center><h1 style="color: white;">Transfer List</h1></center>
      <br><br>
      <center><div id="form">
      <table>
          <tr style="background-color:  #FFA07A;">
              <td><center><b style="color: white;font-size: 20px;">ID</b></center></td>

            <td><center><b style="color: white;font-size: 20px;">Sender Name</b></center></td>

            <td><center><b style="color: white;font-size: 20px;">Receiver Name</b></center></td>

            <td><center><b style="color: white;font-size: 20px;">Amount</b></center></td>

            

          </tr>
          <?php
          $q=$db->query("SELECT *FROM transfer_money");
          while($r1=$q->fetch(PDO::FETCH_OBJ))
          {


          ?>


          <tr>
              <td style="color: white;font-size: 20px;"><center><?=$r1->id; ?></center></td>

            <td style="color: white;font-size: 20px;"><center><?=$r1->sender; ?></center></td>

            <td style="color: white;font-size: 20px;"><center><?=$r1->receiver; ?></center></td>

            <td style="color: white;font-size: 20px;"><center><?=$r1->amount; ?></center></td>
          </tr>
          <?php
        }
        ?>
          
        </table>
        
   </div>  </center>
  



</body>
</html>
