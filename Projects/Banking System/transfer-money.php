                                                   
<?php
session_start();
$con=mysqli_connect('localhost','root','','bank');
$q="select name from customers";
$result=mysqli_query($con,$q);
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
  
    #header{
      margin-top: 60px;
    }
    body{
      background-color: #008080;
    }

</style>
  


<script>
     function random_function()
            {
                var a=document.getElementById("input").value;
        if(a==="Asad"){
         var arr=["Rakib","Topu","Asma","Sifa","Azan","Rahim","Kabir","Jhon","Priyanka"];
         }
         else if(a==="Rakib"){
          var arr=["Asad","Topu","Asma","Sifa","Azan","Rahim","Kabir","Jhon","Priyanka"];
        }
        else if(a==="Topu"){
          var arr=["Asad","Rakib","Asma","Sifa","Azan","Rahim","Kabir","Jhon","Priyanka"];
        }
        else if(a==="Asma"){
          var arr=["Asad","Rakib","Topu","Sifa","Azan","Rahim","Kabir","Jhon","Priyanka"];
         }
         else if(a==="Sifa"){
          var arr=["Asad","Rakib","Topu","Asma","Azan","Rahim","Kabir","Jhon","Priyanka"];
         }
         else if(a==="Azan"){
          var arr=["Asad","Rakib","Topu","Asma","Sifa","Rahim","Kabir","Jhon","Priyanka"];
         }
         else if(a==="Rahim"){
          var arr=["Asad","Rakib","Asma","Sifa","Azan","Kabir","Jhon","Priyanka"];
         }
         else if(a==="Kabir"){
          var arr=["Asad","Rakib","Asma","Sifa","Azan","Rahim","Jhon","Priyanka"];
         }
         else if(a==="Jhon"){
          var arr=["Asad","Rakib","Asma","Sifa","Azan","Rahim","Kabir","Priyanka"];
         }
         else if(a==="Priyanka"){
          var arr=["Asad","Rakib","Asma","Sifa","Azan","Rahim","Kabir","Jhon"];
         }
                var string="";
             
                for(i=0;i<arr.length;i++)
                {
                    string=string+"<option value="+arr[i]+">"+arr[i]+"</option>";
                }
                document.getElementById("output").innerHTML=string;
            }
  </script>





  
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

  





<br>
     <center><h1 style="color: white;">Transfer Money</h1></center>
<br><br>
   <div class="center">
  <form action="send-money.php" method="post">
   <center> <label for="sender" align="left"><b style="font-size: 18px;color: black">Senders Name: &nbsp;</b></label>
    <select id="input" name="sender"style="font-size: 12pt; height: 28px; width:290px;" align="middle" onchange="random_function()">
      <option  selected>Select Name</option>
      <option value="Asad">Asad</option>
      <option value="Rakib">Rakib</option>
      <option value="Topu">Topu</option>
      <option value="Asma">Asma</option>
      <option value="Sifa">Sifa</option>
      <option value="Azan">Azan</option>
            <option value="Rahim">Rahim</option>
      <option value="Kabir">Kabir</option>
      <option value="Jhon">Jhon</option>
      <option value="Priyanka">Priyanka</option>

     
    </select></center><br>
   

   <center> <label for="receiver" align="left"><b style="font-size: 18px;color: black">Receiver Name:&nbsp;</b></label>
    <select id="output" name="receiver"style="font-size: 12pt; height: 28px; width:290px;" align="middle" onchange="random_function1()" >
      <option>Select Name</option>
    </select></center><br>



   <center> <label for="transfer" align="left"><b style="font-size: 18px;color: black">Amount: &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp;</b></label>
    <input type="number"  name="transfer" style="font-size: 12pt; height: 28px; width:290px;" align="middle" required></center> <br><br>


    <center>
    <div class="button1">
    <input class="button" style="font-size: 18px; height: 48px; width:100px;background-color: red;color: white;" type="submit" name="submit" value="Transfer">
    </div></center>
  </form> 
  </div><br><br><br>
  







</body>
</html>
