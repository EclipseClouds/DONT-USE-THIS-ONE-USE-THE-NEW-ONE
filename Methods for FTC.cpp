outthegate()
{
	lm_back.setPower(1);
	lm_front.setPower(1);
	rm_back.setPower(1);
	rm_front.setPower(1);
	sleep (500);
}

robotfullstop()
{
// Bringing the power to 0 and having the robot stop
        lm_back.setPower(0);
        lm_front.setPower(0);
        rm_back.setPower(0);
        rm_front.setPower(0);

        sleep (300);
}

movetowheel()
{

// Moving the robot forward for 2 seconds to start getting in position to spin the wheel
        lm_back.setPower(0.8);
        lm_front.setPower(0.8);
        rm_back.setPower(0.8);
        rm_front.setPower(0.8);

        sleep (2000);
}

movelinear()
{
	lm_back.setPower(1);
        lm_front.setPower(1);
        rm_back.setPower(1);
        rm_front.setPower(1);

        sleep(2500);
}

adjustfromrotation()
{
	lm_back.setDirection(DcMotorSimple.Direction.REVERSE);
        lm_front.setDirection(DcMotorSimple.Direction.REVERSE);
        rm_back.setDirection(DcMotorSimple.Direction.FORWARD);
        rm_front.setDirection(DcMotorSimple.Direction.FORWARD);

        lm_back.setPower(-0.5);
        lm_front.setPower(-0.5);
        rm_back.setPower(0.5);
        rm_front.setPower(0.5);

        sleep(300);

}

createrotationleft()
{
	lm_back.setPower(-0.5);
        lm_front.setPower(-0.5);
        rm_back.setPower(0.5);
        rm_front.setPower(0.5);

        sleep(500);
}