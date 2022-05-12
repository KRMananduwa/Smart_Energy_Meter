<html>
<head>
    <title>Login And Registration Form</title>
    <link rel="stylesheet" href="style.css">
</head>
<body>
  <div class="hero">
    <div class="hero-text">
      <h1 style="font-size:50px">Smart Meter</h1>
    </div>
    <div class="form-box">
      <div>
      </div>
      <div class="button-box">
      <div id="btn"></div>
      <button type="button" class="toggle-btn" onclick="login()">Log In</button>
      <button type="button" class="toggle-btn" onclick="register()">Register</button>
      </div>
      <form action="validation.php" id="login" class="input-group" method="post">
        <input type="text" name="user" class="input-field" placeholder="User Id" required>
        <input type="password" name="password" class="input-field" placeholder="Enter Password" required>
        <input type="checkbox" class="check-box"><span>Remember Password</span>
        <button type="submit" class="submit-btn">Log in</button>
      </form>
      <form action="registration.php" id="register" class="input-group" method="post">
        <input type="text" name="user" class="input-field" placeholder="User Id" required>
        <input type="email" name="email" class="input-field" placeholder="Email" required>
        <input type="password" name="password" class="input-field" placeholder="Enter Password" required>
        <input type="checkbox" class="check-box"><span>I agree to the terms & conditions.</span>
        <button type="submit" class="submit-btn">Register</button>
      </form>
    </div>
  </div>
  <script>
  var x = document.getElementById("login");
  var y = document.getElementById("register");
  var z = document.getElementById("btn");
  
  function register(){
  	x.style.left = "-400px";
    y.style.left = "50px";
    z.style.left = "110px";
  }
  function login(){
  	x.style.left = "50px";
    y.style.left = "450px";
    z.style.left = "0";
  }
  </script> 
</body>
</html>