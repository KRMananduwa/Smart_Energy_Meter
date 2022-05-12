<?php
class acs712rawval{
 public $link='';
 function __construct($rawval){
  $this->connect();
  $this->storeInDB($rawval);
 }
 
 function connect(){
  $this->link = mysqli_connect('localhost','root','') or die('Cannot connect to the DB');
  mysqli_select_db($this->link,'<acs712_raw_data>') or die('Cannot select the DB');
 }
 
 function storeInDB($rawval){
  $query = "insert into <acs712rawval> set rawval='".$rawval."'";
  $result = mysqli_query($this->link,$query) or die('Errant query:  '.$query);
 }
 
}
if($_GET['rawval'] != ''){
 $acs712rawval=new acs712rawval($_GET['rawval']);
}
?>