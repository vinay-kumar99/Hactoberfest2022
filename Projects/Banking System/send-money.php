<?php
session_start();
$con=mysqli_connect('localhost','root','','bank');
$name1=$_POST['sender'];
$q="select amount from customers where name='$name1'";
$result=mysqli_query($con,$q);
$row=mysqli_fetch_array($result);
$var=$row['amount'];
$from=$_POST['sender'];
$to=$_POST['receiver'];
$q1="select amount from customers where name='$to'";
$result1=mysqli_query($con,$q1);
$row=mysqli_fetch_array($result1);
$var1=$row['amount'];
session_destroy();
if ( $var >= $_POST["transfer"] )
{
    $sub=$var-$_POST["transfer"];
    $q="update customers set amount='$sub' where name='$from' ";
    $result=mysqli_query($con,$q);
    $sum=$var1+$_POST["transfer"];
    $q="update customers set amount='$sum' where name='$to' ";
    $result=mysqli_query($con,$q);
  $c=$_POST["transfer"];
  $q="insert into transfer_money(sender,receiver,amount)
    values('$from','$to',$c)";
  $result=mysqli_query($con,$q);
    
        $message="Successful transfer";
   echo"<script type='text/javascript'>alert('$message');
   </script>";
    include 'all-customers.php';
    
}
else
{
    $message="Insufficient Balance";
   echo"<script type='text/javascript'>alert('$message');
   </script>";
    
    include 'all-customers.php';

}
?>