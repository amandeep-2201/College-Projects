<?php

require_once ('tcpdf/tcpdf.php'); // Include TCPDF library

$conn = mysqli_connect('localhost', 'root', '', 'contact_db') or die ('connection failed');

if (isset ($_POST['submit'])) {

    $name = mysqli_real_escape_string($conn, $_POST['name']);
    $age = mysqli_real_escape_string($conn, $_POST['age']);
    $gender = mysqli_real_escape_string($conn, $_POST['gender']);
    $number = $_POST['number'];
    $email = mysqli_real_escape_string($conn, $_POST['email']);
    $problem = mysqli_real_escape_string($conn, $_POST['problem']);
    $date = $_POST['date'];

    $insert = mysqli_query($conn, "INSERT INTO `contact_form`(name, age, gender, number, email, problem, date) VALUES('$name','$age','$gender','$number','$email','$problem','$date')") or die ('query failed');

    if ($insert) {
        $message[] = 'appointment made successfully!';
        // Generate PDF receipt
        $pdf = new TCPDF();
        $pdf->setPrintHeader(false);
        $pdf->setPrintFooter(false);
        $pdf->AddPage();
        $pdf->SetFont('helvetica', '', 12);

        // Add hospital logo and center align
        $logo_path = 'image/logo.jpg';
        $logo_width = 50; // Adjust as needed
        $pdf->Image($logo_path, ($pdf->getPageWidth() - $logo_width) / 2, 15, $logo_width, '', 'JPG');

        // Set position for hospital name and address
        $pdf->SetFont('helvetica', 'B', 14);
        $pdf->Cell(0, 50, ' ', 0, 1, 'C');
        $pdf->SetTextColor(0, 0, 0); // Black color for text
        $pdf->Cell(0, 10, 'City Hospital', 0, 1, 'C');
        $pdf->SetFont('helvetica', '', 12);
        $pdf->Cell(0, 10, '123, Paschim Vihar', 0, 1, 'C');
        $pdf->Cell(0, 10, 'Delhi - 110063', 0, 1, 'C');

        $pdf->Ln(20); // Add some space

        $content = "<u><b><h1>Appointment Confirmation Receipt</h1></b></u><br>";

        // Add appointment details
        $content .= "<b>Name:</b> $name<br>";
        $content .= "<b>Age:</b> $age<br>";
        $content .= "<b>Gender:</b> $gender<br>";
        $content .= "<b>Phone Number:</b> $number<br>";
        $content .= "<b>Email:</b> $email<br>";
        $content .= "<b>Problem:</b> $problem<br>";
        $content .= "<b>Date:</b> $date<br>";

        $pdf->writeHTML($content, true, false, true, false, '');

        $file_name = 'appointment_receipt_' . time() . '.pdf'; // Generate a unique filename
        $pdf->Output($file_name, 'D'); // 'D' option to force download

        exit;

    } else {
        $message[] = 'appointment failed';
    }
}

if (isset ($_POST['submit_review'])) {

    $name = mysqli_real_escape_string($conn, $_POST['name']);
    $rating = $_POST['rating'];
    $comment = mysqli_real_escape_string($conn, $_POST['comment']);

    $insert_review = mysqli_query($conn, "INSERT INTO `reviews`(name, rating, comment) VALUES('$name','$rating','$comment')") or die ('query failed');

    if ($insert_review) {
        $review_message = 'Review submitted successfully!';
    } else {
        $review_message = 'Failed to submit review';
    }
}
?>

<!DOCTYPE html>
<html lang="en">

<head>
    <meta charset="UTF-8">
    <meta http-equiv="X-UA-Compatible" content="IE=edge">
    <meta name="viewport" content="width=device-width, initial-scale=1.0">
    <title>City Hospital</title>

    <!-- font awesome cdn link  -->
    <link rel="stylesheet" href="https://cdnjs.cloudflare.com/ajax/libs/font-awesome/5.15.4/css/all.min.css">

    <!-- custom css file link  -->
    <link rel="stylesheet" href="css/style.css">

</head>

<body>

    <!-- header section starts  -->

    <header class="header">

        <a href="#" class="logo"> <i class="fas fa-heartbeat"></i> <strong>City</strong>Hospital </a>

        <nav class="navbar">
            <a href="#home">home</a>
            <a href="#about">about</a>
            <a href="#services">services</a>
            <a href="#doctors">doctors</a>
            <a href="#appointment">appointment</a>
            <a href="#review">review</a>
            <a href="#blogs">blogs</a>
        </nav>

        <div id="menu-btn" class="fas fa-bars"></div>

    </header>

    <!-- header section ends -->

    <!-- home section starts  -->

    <section class="home" id="home">

        <div class="image">
            <img src="image/home-img.svg" alt="">
        </div>

        <div class="content">
            <h3>we take care of your healthy life</h3>
            <p> A person who has good physical health is likely to have bodily functions and processes working at their
                peak.</p>
            <a href="#appointment" class="btn"> book appointment<span class="fas fa-chevron-right"></span> </a>
        </div>

    </section>

    <!-- home section ends -->

    <!-- icons section starts  -->

    <section class="icons-container">

        <div class="icons">
            <i class="fas fa-user-md"></i>
            <h3>150+</h3>
            <p>doctors at work</p>
        </div>

        <div class="icons">
            <i class="fas fa-users"></i>
            <h3>1030+</h3>
            <p>satisfied patients</p>
        </div>

        <div class="icons">
            <i class="fas fa-procedures"></i>
            <h3>490+</h3>
            <p>bed facility</p>
        </div>

        <div class="icons">
            <i class="fas fa-hospital"></i>
            <h3>70+</h3>
            <p>available hospitals</p>
        </div>

    </section>

    <!-- icons section ends -->

    <!-- about section starts  -->

    <section class="about" id="about">

        <h1 class="heading"> <span>about</span> us </h1>

        <div class="row">

            <div class="image">
                <img src="image/about-img.svg" alt="">
            </div>

            <div class="content">
                <h3>take the world's best quality treatment</h3>
                <p>Welcome to City Hospital – a hub of cutting-edge healthcare in the heart of our community. Our expert
                    team of specialists and state-of-the-art facilities ensure comprehensive medical services. From
                    cardiology to orthopedics, we prioritize your well-being. Established in 1986, our vision is rooted
                    in providing top-notch, patient-centric care. Join us at City Hospital, where health meets
                    innovation.</p>
                <<a href="about.html" class="btn"> learn more <span class="fas fa-chevron-right"></span> </a>
            </div>

        </div>

    </section>

    <!-- about section ends -->

    <!-- services section starts  -->

    <section class="services" id="services">

        <h1 class="heading"> our <span>services</span> </h1>

        <div class="box-container">

            <div class="box">

                <i class="fas fa-notes-medical"></i>
                <h3>free checkups</h3>
                <p>City Hospital offers complimentary checkups, ensuring accessibility to preventive healthcare for all.
                </p><br><br>
                <a href="service1.html" class="btn"> learn more <span class="fas fa-chevron-right"></span> </a>

            </div>

            <div class="box">
                <i class="fas fa-ambulance"></i>
                <h3>24/7 ambulance</h3>
                <p>Our dedicated ambulance service operates around the clock, providing swift and reliable emergency
                    transport for patients in need.</p>
                <a href="service2.html" class="btn"> learn more <span class="fas fa-chevron-right"></span> </a>
            </div>

            <div class="box">
                <i class="fas fa-user-md"></i>
                <h3>expert doctors</h3>
                <p>City Hospital is staffed with a team of highly skilled and experienced doctors, committed to
                    delivering top-notch medical care and expertise.</p>
                <a href="service3.html" class="btn"> learn more <span class="fas fa-chevron-right"></span> </a>
            </div>

            <div class="box">
                <i class="fas fa-pills"></i>
                <h3>medicines</h3>
                <p>We provide a comprehensive pharmacy service, ensuring that patients have easy access to a range of
                    prescribed medications for their treatment.</p>
                <a href="service4.html" class="btn"> learn more <span class="fas fa-chevron-right"></span> </a>
            </div>

            <div class="box">
                <i class="fas fa-procedures"></i>
                <h3>bed facility</h3>
                <p>Comfortable and well-equipped bed facilities are available, ensuring a restful and supportive
                    environment for patients during their stay.</p><br><br>
                <a href="service5.html" class="btn"> learn more <span class="fas fa-chevron-right"></span> </a>
            </div>

            <div class="box">
                <i class="fas fa-heartbeat"></i>
                <h3>total care</h3>
                <p>City Hospital is committed to providing holistic healthcare, addressing physical, emotional, and
                    psychological aspects, ensuring comprehensive well-being for every patient.</p>
                <a href="service6.html" class="btn"> learn more <span class="fas fa-chevron-right"></span> </a>
            </div>

            <div class="box">
                <i class="fas fa-hand-holding-medical"></i>
                <h3>Blood Donation</h3>
                <p>Contributing to community health, we organize regular blood donation camps, fostering a culture of
                    voluntary blood donation to meet critical medical needs.</p>
                <a href="service7.html" class="btn"> learn more <span class="fas fa-chevron-right"></span> </a>
            </div>

            <div class="box">
                <i class="fas fa-coffee"></i>
                <h3>24/7 Canteen</h3>
                <p>Our round-the-clock canteen ensures that patients, their families, and hospital staff have access to
                    nourishing meals and refreshments at any time.</p><br><br>
                <a href="service8.html" class="btn"> learn more <span class="fas fa-chevron-right"></span> </a>
            </div>


        </div>

    </section>

    <!-- services section ends -->



    <!-- doctors section starts  -->

    <section class="doctors" id="doctors">

        <h1 class="heading"> our <span>doctors</span> </h1>

        <div class="box-container">

            <div class="box">
                <img src="image/doctor1.jpeg" alt="">
                <h3>Dr. Vikram Singh Rathore</h3>
                <span>Pediatric Cardiology</span>
                <br>
                <a href="doctor1.html" class="btn">Know More</a>

            </div>

            <div class="box">
                <img src="image/doctor2.jpeg" alt="">
                <h3>Dr. Harcharan Singh</h3>
                <span>Orthopedic Surgery</span>
                <br>
                <a href="doctor2.html" class="btn">Know More</a>
            </div>

            <div class="box">
                <img src="image/doctor3.jpeg" alt="">
                <h3>Dr. Sunil Reddy</h3>
                <span>Neurology</span>
                <br>
                <a href="doctor3.html" class="btn">Know More</a>
            </div>

            <div class="box">
                <img src="image/doctor4.jpeg" alt="">
                <h3>Dr. Nisha Gupta</h3>
                <span>Cardiothoracic Surgery</span>
                <br>
                <a href="doctor4.html" class="btn">Know More</a>
            </div>

            <div class="box">
                <img src="image/doctor5.jpeg" alt="">
                <h3>Dr. Sanjay Mishra</h3>
                <span>Gastroenterology</span>
                <br>
                <a href="doctor5.html" class="btn">Know More</a>
            </div>

            <div class="box">
                <img src="image/doctor6.jpeg" alt="">
                <h3>Dr. Priya Chatterjee</h3>
                <span>Pulmonology</span>
                <br>
                <a href="doctor6.html" class="btn">Know More</a>
            </div>
        </div>

    </section>

    <!-- doctors section ends -->

    <!-- appointmenting section starts   -->

    <section class="appointment" id="appointment">

        <h1 class="heading"> <span>appointment</span> now </h1>

        <div class="row">

            <div class="image">
                <img src="image/appointment-img.svg" alt="">
            </div>

            <form action="<?php echo $_SERVER['PHP_SELF']; ?>" method="post">
                <?php
                if (isset ($message)) {
                    echo '<p class="message">' . $message . '</p>';
                }
                ?>
                <h3>make appointment</h3>
                <input type="text" name="name" placeholder="Name" class="box">
                <input type="number" name="age" placeholder="Age" class="box">
                <input type="text" name="gender" placeholder="Gender" class="box">
                <input type="number" name="number" placeholder="Phone Number" class="box">
                <input type="email" name="email" placeholder="Email" class="box">
                <input type="text" name="problem" placeholder="Your Problem" class="box">
                <input type="datetime-local" name="date" class="box">
                <input type="submit" name="submit" value="Book Appointment" class="btn">
            </form>

        </div>

    </section>

    <!-- appointmenting section ends -->

    <!-- review section starts  -->

    <section class="review" id="review">

        <h1 class="heading"> client's <span>review</span> </h1>

        <div class="box-container">

            <div class="box">
                <img src="image/nirpesh.jpg" alt="">
                <h3>Nirpesh Gupta</h3>
                <div class="stars">
                    <i class="fas fa-star"></i>
                    <i class="fas fa-star"></i>
                    <i class="fas fa-star"></i>
                    <i class="fas fa-star"></i>
                    <i class="fas fa-star-half-alt"></i>
                </div>
                <p class="text">I recently had an excellent experience at City Hospital. The staff was incredibly
                    attentive and compassionate, making me feel comfortable and well-cared-for throughout my visit. The
                    facility was clean and well-maintained, and the medical professionals exhibited a high level of
                    expertise. Overall, I highly recommend City Hospital for their exceptional service and commitment to
                    patient care.</p>
            </div>

            <div class="box">
                <img src="image/Ranjana.jpg" alt="">
                <h3>Rajana Chopra</h3>
                <div class="stars">
                    <i class="fas fa-star"></i>
                    <i class="fas fa-star"></i>
                    <i class="fas fa-star"></i>
                    <i class="fas fa-star"></i>
                    <i class="fas fa-star-half-alt"></i>
                </div>
                <p class="text">I had the best experience at City Hospital, and I am compelled to share my thoughts. The
                    staff was incredibly attentive and caring, making me feel well-supported throughout my stay. The
                    medical team exhibited a high level of expertise and professionalism, ensuring that I received the
                    best possible care. I highly recommend City Hospital for their exceptional service and compassionate
                    approach to patient care.</p>
            </div>

            <div class="box">
                <img src="image/Ramlaal.jpg" alt="">
                <h3>Ram Laal Prasad</h3>
                <div class="stars">
                    <i class="fas fa-star"></i>
                    <i class="fas fa-star"></i>
                    <i class="fas fa-star"></i>
                    <i class="fas fa-star"></i>
                    <i class="fas fa-star-half-alt"></i>
                </div>
                <p class="text">Few days back I visited City Hospital. From the moment I walked in, the staff was
                    welcoming and attentive. The facility was clean, and the waiting time was minimal. The medical
                    professionals were knowledgeable, empathetic, and took the time to explain procedures and answer any
                    questions.Overall, City Hospital is a top-notch healthcare facility, and I would highly recommend it
                    to others seeking quality medical care.</p>
            </div>

        </div>
        <h1 class="heading"> Share Your <span>Review</span> </h1>

        <div class="box">
            <h1>
                <form action="<?php echo $_SERVER['PHP_SELF']; ?>" method="post"
                    style="max-width: 400px; margin: 0 auto;">
                    <?php
                    if (isset ($review_message)) {
                        echo '<p class="message" style="background-color: #f0f0f0; color : #16a085; padding: 10px; border-radius: 5px; margin-bottom: 10px;">' . $review_message . '</p>';
                    }
                    ?>
                    <input type="text" name="name" placeholder="Your Name" class="box"
                        style="width: 100%; padding: 10px; margin-bottom: 10px; border: 1px solid #ccc; border-radius: 5px;">
                    <select name="rating" class="box"
                        style="width: 100%; padding: 10px; margin-bottom: 10px; border: 1px solid #ccc; border-radius: 5px;">
                        <option value="1">1 Star</option>
                        <option value="1.5">1.5 Stars</option>
                        <option value="2">2 Stars</option>
                        <option value="2.5">2.5 Stars</option>
                        <option value="3">3 Stars</option>
                        <option value="3.5">3.5 Stars</option>
                        <option value="4">4 Stars</option>
                        <option value="4.5">4.5 Stars</option>
                        <option value="5">5 Stars</option>
                    </select>
                    <textarea name="comment" placeholder="Your Review" class="box"
                        style="width: 100%; padding: 10px; margin-bottom: 10px; border: 1px solid #ccc; border-radius: 5px;"></textarea>
                    <input type="submit" name="submit_review" value="Submit Review" class="btn"
                        style="width: 100%; padding: 10px; background-color: #16a085; color: white; border: none; border-radius: 5px; cursor: pointer;">
                </form>

            </h1>
        </div>

    </section>

    <!-- review section ends -->

    <!-- blogs section starts  -->

    <section class="blogs" id="blogs">

        <h1 class="heading"> our <span>blogs</span> </h1>

        <div class="box-container">

            <div class="box">
                <div class="image">
                    <img src="image/blog1.jpg" alt="">
                </div>
                <div class="content">
                    <div class="icon">
                        <a href="#"> <i class="fas fa-calendar"></i> Mar 07, 2024 </a>
                        <a href="#"> <i class="fas fa-user"></i> Dr. Vinod Raina </a>
                    </div>
                    <h3>Myths and Facts About Cancer</h3>
                    <p>Dispelling Misconceptions for Better Understanding and Awareness</p>
                    <a href="blog1.html" class="btn"> learn more <span class="fas fa-chevron-right"></span> </a>
                </div>
            </div>

            <div class="box">
                <div class="image">
                    <img src="image/blog2.jpg" alt="">
                </div>
                <div class="content">
                    <div class="icon">
                        <a href="#"> <i class="fas fa-calendar"></i> 5 March,2024 </a>
                        <a href="#"> <i class="fas fa-user"></i> Dr. Deepti Khatuja </a>
                    </div>
                    <h3>Cancer and Nutrition: A Holistic Approach</h3>
                    <p>Relationship between cancer and nutrition and discuss strategies </p>
                    <a href="blog2.html" class="btn"> learn more <span class="fas fa-chevron-right"></span> </a>
                </div>
            </div>

            <div class="box">
                <div class="image">
                    <img src="image/blog3.png" alt="">
                </div>
                <div class="content">
                    <div class="icon">
                        <a href="#"> <i class="fas fa-calendar"></i> 4 March, 2024 </a>
                        <a href="#"> <i class="fas fa-user"></i> Dr. Rahul Bhargava </a>
                    </div>
                    <h3>CAR T cell therapy</h3><br>
                    <p>Immunotherapy that involves reprogramming a patient's T cells to better recognize and attack
                        cancer cells.</p>
                    <a href="blog3.html" class="btn"> learn more <span class="fas fa-chevron-right"></span> </a>
                </div>
            </div>
            <div class="box">
                <div class="image">
                    <img src="image/blog4.png" alt="">
                </div>
                <div class="content">
                    <div class="icon">
                        <a href="#"> <i class="fas fa-calendar"></i> 5 March, 2024 </a>
                        <a href="#"> <i class="fas fa-user"></i> Dr. Saurabh Yatish Bansal </a>
                    </div>
                    <h3>Migraine: Understanding Symptoms, Triggers, and Treatment</h3>
                    <p> It is a complex disorder with a wide range of triggers and manifestations, affecting millions of
                        people worldwide.</p>
                    <a href="blog4.html" class="btn"> learn more <span class="fas fa-chevron-right"></span> </a>
                </div>
            </div>
            <div class="box">
                <div class="image">
                    <img src="image/blog5.png" alt="">
                </div>
                <div class="content">
                    <div class="icon">
                        <a href="#"> <i class="fas fa-calendar"></i> 5 March, 2024 </a>
                        <a href="#"> <i class="fas fa-user"></i> Dr. Anita Sethi </a>
                    </div>
                    <h3>LASIK Surgery: What to Expect and Who Is a Candidate</h3>
                    <p>LASIK (Laser-Assisted In Situ Keratomileusis) surgery has revolutionized vision correction,
                        offering millions of people around the world the opportunity to reduce or eliminate their
                        dependence on glasses or contact lenses</p>
                    <a href="blog5.html" class="btn"> learn more <span class="fas fa-chevron-right"></span> </a>
                </div>
            </div>
            <div class="box">
                <div class="image">
                    <img src="image/blog6.png" alt="">
                </div>
                <div class="content">
                    <div class="icon">
                        <a href="#"> <i class="fas fa-calendar"></i> 5 March, 2024 </a>
                        <a href="#"> <i class="fas fa-user"></i> Dr. Anita Sethi </a>
                    </div>
                    <h3>Understanding Common Eye Conditions: Causes, Symptoms, and Treatment Options</h3>
                    <p>essential for maintaining optimal vision and seeking timely medical intervention</p>
                    <a href="blog6.html" class="btn"> learn more <span class="fas fa-chevron-right"></span> </a>
                </div>
            </div>

        </div>

    </section>

    <!-- blogs section ends -->

    <!-- footer section starts  -->

    <section class="footer">

        <div class="box-container">

            <div class="box">
                <h3>quick links</h3>
                <a href="#home"> <i class="fas fa-chevron-right"></i> home </a>
                <a href="#about"> <i class="fas fa-chevron-right"></i> about </a>
                <a href="#services"> <i class="fas fa-chevron-right"></i> services </a>
                <a href="#doctors"> <i class="fas fa-chevron-right"></i> doctors </a>
                <a href="#appointment"> <i class="fas fa-chevron-right"></i> appointment </a>
                <a href="#review"> <i class="fas fa-chevron-right"></i> review </a>
                <a href="#blogs"> <i class="fas fa-chevron-right"></i> blogs </a>
            </div>

            <div class="box">
                <h3>our services</h3>
                <a href="service1.html"> <i class="fas fa-chevron-right"></i> Free Checkups </a>
                <a href="service2.html"> <i class="fas fa-chevron-right"></i> 24/7 Ambulance </a>
                <a href="service3.html"> <i class="fas fa-chevron-right"></i> Expert Doctors </a>
                <a href="service4.html"> <i class="fas fa-chevron-right"></i> Medicines </a>
                <a href="service5.html"> <i class="fas fa-chevron-right"></i> Bed Facility </a>
                <a href="service6.html"> <i class="fas fa-chevron-right"></i> Total Care </a>
                <a href="service7.html"> <i class="fas fa-chevron-right"></i> Blood Donation </a>
                <a href="service8.html"> <i class="fas fa-chevron-right"></i> 24/7 Canteen </a>
            </div>

            <div class="box">
                <h3>appointment info</h3>
                <a> <i class="fas fa-phone"></i> +91 8287918611 </a>
                <a> <i class="fas fa-phone"></i> +91 8368897672 </a>
                <a href="https://shorturl.at/cgX49"> <i class="fas fa-envelope"></i> goyalsarthak425@gmail.com </a>
                <a href="https://maps.app.goo.gl/VZaD3i1js7aiyd2cA"> <i class="fas fa-map-marker-alt"></i> New Delhi,
                    India </a>
            </div>

            <div class="box">
                <h3>Follow Us</h3>
                <a href="https://shorturl.at/lty15"> <i class="fab fa-twitter"></i> twitter </a>
                <a href="https://www.instagram.com/amandeep_2201/"> <i class="fab fa-instagram"></i> instagram </a>
                <a href="https://shorturl.at/bglw0"> <i class="fab fa-linkedin"></i> linkedin </a>
            </div>

        </div>

        <div class="credit"> created by <span>Amandeep Singh, Sarthak Goyal & Muskan Puri</span> | all rights reserved
        </div>

    </section>

    <!-- footer section ends -->


    <!-- js file link  -->
    <script src="js/script.js"></script>

</body>

</html>