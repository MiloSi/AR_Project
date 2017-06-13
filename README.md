# AR_Project
Study and Study <br>

<h2> face detected </h2>

<p> I learned how to detecting face using opencv. But original program  was too slow. <br>
My thought is to resize grayscale image 0.5 and operated using OpenCL. </p> <br>

...

    // rememeber that my opecv version is 3.2
    Mat frame; 
	  UMat gray;
  
    /*
      ...
    */
    
    cvtColor(frame, gray, COLOR_BGR2GRAY);
		resize(gray, gray, Size(width * 0.5, height * 0.5));
		equalizeHist(gray, gray);
...
