package org.firstinspires.ftc.teamcode;

import com.qualcomm.robotcore.eventloop.opmode.Autonomous;
import com.qualcomm.robotcore.eventloop.opmode.LinearOpMode;
import com.qualcomm.robotcore.hardware.DcMotor;
import com.qualcomm.robotcore.hardware.DcMotorSimple;

@Autonomous(name = "ExampleAutonomous", group = "Example")
public class TestAutonomous extends LinearOpMode {

    // Defining Variable
    DcMotor lm_back;
    DcMotor lm_front;
    DcMotor rm_back;
    DcMotor rm_front;
    //DcMotor wheelspin;

    @Override
    public void runOpMode() throws InterruptedException {
        // Setting Variables and mapping them to the phone's name that way it can transmit the information from the code onto the robot, we need to reverse the direction of the right motors so that they'll turn in the same direction as the left ones
        lm_back = hardwareMap.dcMotor.get("lm_back");
        lm_front = hardwareMap.dcMotor.get("lm_front");
        rm_back = hardwareMap.dcMotor.get("rm_back");
        rm_front = hardwareMap.dcMotor.get("rm_front");
        rm_back.setDirection(DcMotorSimple.Direction.REVERSE);
        rm_front.setDirection(DcMotorSimple.Direction.REVERSE);
        //wheelspin = hardwareMap.dcMotor.get("wheelspin");

        // Does what is says, wait for the command to start
        waitForStart();

        // Bringing the robot out from the wall for 1 second

        lm_back.setPower(-0.3);
        lm_front.setPower(0.3);
        rm_back.setPower(0.3);
        rm_front.setPower(-0.3);

        sleep (500);

        // Bringing the power to 0 and having the robot stop
        lm_back.setPower(0);
        lm_front.setPower(0);
        rm_back.setPower(0);
        rm_front.setPower(0);

        sleep (300);

        lm_back.setPower(0.5);
        lm_front.setPower(0.5);
        rm_back.setPower(0.5);
        rm_front.setPower(0.5);

        sleep(2000);

        // Bringing the power to 0 and having the robot stop
        lm_back.setPower(0);
        lm_front.setPower(0);
        rm_back.setPower(0);
        rm_front.setPower(0);

        sleep (300);
        /*
        lm_back.setPower(0.5);
        lm_front.setPower(0.5);
        rm_back.setPower(0.5);
        rm_front.setPower(0.5);

        sleep (500);




        // Turning the robot right
        lm_back.setPower(.5);
        lm_front.setPower(.5);
        rm_back.setPower(-0.5);
        rm_front.setPower(-0.5);

        sleep(500);
        // We need to set to 0 here because we want the robot to fully stop and ensure consistency
        lm_back.setPower(0);
        lm_front.setPower(0);
        rm_back.setPower(0);
        rm_front.setPower(0);
        sleep(300);

        // Moving the robot forward for 2 seconds to start getting in position to spin the wheel
        lm_back.setPower(0.3);
        lm_front.setPower(0.3);
        rm_back.setPower(0.3);
        rm_front.setPower(0.3);

        sleep (2000);



        lm_back.setPower(0);
        lm_front.setPower(0);
        rm_back.setPower(0);
        rm_front.setPower(0);
        sleep(300);

         */

        // We want the robot to rotate here

        lm_back.setPower(-0.2);
        lm_front.setPower(-0.2);
        rm_back.setPower(0.2);
        rm_front.setPower(0.2);

        sleep(800);
        // Move into position so wheel has contact with susan (the ducky thing)
        lm_back.setPower(0.1);
        lm_front.setPower(0.1);
        rm_back.setPower(0.1);
        rm_front.setPower(0.1);

        sleep (1000);

        lm_back.setPower(0);
        lm_front.setPower(0);
        rm_back.setPower(0);
        rm_front.setPower(0);

        sleep(300);

        // spinning the susan (the ducky thing)
        //wheelspin.setPower(1);
        //sleep (1500);
        //wheelspin.setPower(0);
        //sleep(300);

        // Move horizontally to the left out away from the susan (the ducky thing)
        lm_back.setPower(0.7);
        lm_front.setPower(-0.7);
        rm_back.setPower(0.7);
        rm_front.setPower(-0.7);

        sleep(800);

        // set the direction so that the power when positive is actually equal to moving backwards
        lm_back.setDirection(DcMotorSimple.Direction.REVERSE);
        lm_front.setDirection(DcMotorSimple.Direction.REVERSE);
        rm_back.setDirection(DcMotorSimple.Direction.FORWARD);
        rm_front.setDirection(DcMotorSimple.Direction.FORWARD);

        // adjusting from the rotation earlier
        lm_back.setPower(-0.2);
        lm_front.setPower(-0.2);
        rm_back.setPower(0.2);
        rm_front.setPower(0.2);

        sleep(800);

        // parking into warehouse
        lm_back.setPower(0.5);
        lm_front.setPower(0.5);
        rm_back.setPower(0.5);
        rm_front.setPower(0.5);

        sleep(1500);

















    }
}
