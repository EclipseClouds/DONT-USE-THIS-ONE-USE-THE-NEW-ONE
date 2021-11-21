package org.firstinspires.ftc.teamcode;

import static com.qualcomm.robotcore.hardware.DcMotor.RunMode.RUN_USING_ENCODERS;

import com.qualcomm.robotcore.eventloop.opmode.Disabled;
import com.qualcomm.robotcore.eventloop.opmode.OpMode;
import com.qualcomm.robotcore.eventloop.opmode.TeleOp;
import com.qualcomm.robotcore.hardware.DcMotor;
import com.qualcomm.robotcore.hardware.DcMotorSimple;
import com.qualcomm.robotcore.hardware.Servo;
import com.qualcomm.robotcore.util.ElapsedTime;
import com.qualcomm.robotcore.eventloop.opmode.LinearOpMode;
import com.qualcomm.robotcore.util.Range;

@TeleOp(name = "TestMotor", group = "IterativeOpmode")
public class TestMotor extends OpMode
{
    // Defining Variables
    private ElapsedTime runtime = new ElapsedTime();
    private DcMotor lm_back = null;
    private DcMotor lm_front = null;
    private DcMotor rm_back = null;
    private DcMotor rm_front = null;
    private DcMotor spin_bot = null;
    private DcMotor arm = null;
    static final double Motor_Tick_Count = 356.3;
    private Servo armservo = null;
    private double servoposition = 0.5;
    static final double MAX_POS = 0.55;
    static final double MIN_POS = 0.45;
    private DcMotor wheelspin = null;

    @Override
    public void init()
    {
        // Setup direction and get configuration name
        telemetry.addData("Status", "Initialized");
        lm_back = hardwareMap.get(DcMotor.class, "lm_back");
        lm_front = hardwareMap.get(DcMotor.class, "lm_front");
        rm_back = hardwareMap.get(DcMotor.class, "rm_back");
        rm_front = hardwareMap.get(DcMotor.class, "rm_front");
        rm_back.setDirection(DcMotorSimple.Direction.REVERSE);
        rm_front.setDirection(DcMotorSimple.Direction.REVERSE);
        spin_bot = hardwareMap.get(DcMotor.class, "spin_bot");
        arm = hardwareMap.get(DcMotor.class, "arm");
        armservo = hardwareMap.get(Servo.class, "armservo");
        wheelspin = hardwareMap.get(DcMotor.class, "wheelspin");

        armservo.setPosition(servoposition);





        telemetry.addData("Status", "Initialized");
    }

    @Override
    public void init_loop() {
    }

    @Override
    public void start() {runtime.reset();}

    @Override
    public void loop()
    {
        double r = Math.hypot(gamepad1.left_stick_x, gamepad1.left_stick_y);
        double robotAngle = Math.atan2(gamepad1.left_stick_y, (gamepad1.left_stick_x * -1)) - Math.PI / 4;
        double rightX = gamepad1.right_stick_x;
        final double v1 = r * Math.cos(robotAngle) * -1 + (rightX / 1.5);
        final double v2 = r * Math.sin(robotAngle) * -1 - (rightX / 1.5);
        final double v3 = r * Math.sin(robotAngle) * -1 + (rightX / 1.5);
        final double v4 = r * Math.cos(robotAngle) * -1 - (rightX / 1.5);

        lm_back.setPower(v3);
        lm_front.setPower(v1);
        rm_back.setPower(v4);
        rm_front.setPower(v2);

        //telemetry.addData("Status", "Run Time: " + runtime.toString());
        //telemetry.addData("Caption","Datapoint"); // figures out what state / things the robot is at, like the power of the motors currently and what the sensors are outputting
        //telemetry.addData("Back Left motor power", lm_back.getPower());
        //telemetry.addData("Front Left motor power", lm_front.getPower());
        //telemetry.addData("Back Right motor power", rm_back.getPower());
        //telemetry.addData("Front Right motor power", rm_front.getPower());
        //telemetry.addData("Spin_bot motor power", spin_bot.getPower());

        final double v5 = gamepad2.right_stick_y;
        spin_bot.setPower(v5);

        double first_level = 300;
        double second_level = 400;
        double third_level = 600;
        double decrease = -50;
        if (gamepad2.x == true)
        {
            arm.setMode(DcMotor.RunMode.STOP_AND_RESET_ENCODER);
            arm.setTargetPosition((int)first_level);
            arm.setPower(1);

            arm.setMode(DcMotor.RunMode.RUN_TO_POSITION);

            while (arm.isBusy())
            {

            }
            gamepad2.x = false;

        }


        if (gamepad2.a == true)
        {
            arm.setMode(DcMotor.RunMode.STOP_AND_RESET_ENCODER);
            arm.setTargetPosition((int)second_level);
            arm.setPower(1);
            arm.setMode(DcMotor.RunMode.RUN_TO_POSITION);

            while (arm.isBusy()) {

            }
            gamepad2.y = false;
        }

        if (gamepad2.b == true)
        {
            arm.setMode(DcMotor.RunMode.STOP_AND_RESET_ENCODER);
            arm.setTargetPosition((int)decrease);
            arm.setPower(1);
            arm.setMode(DcMotor.RunMode.RUN_TO_POSITION);
            while (arm.isBusy())
            {

            }
            gamepad2.b = false;
        }


        if (gamepad2.left_bumper)
        {
            armservo.setPosition(1);
        }
        if (gamepad2.right_bumper)
        {
            armservo.setPosition(0.5);
        }
        if (gamepad2.y)
        {
            armservo.setPosition(0);
        }

        telemetry.addData("servo", "%.2f", servoposition);
        if (gamepad2.dpad_up)
            wheelspin.setPower(1);
        if (gamepad2.dpad_down)
            wheelspin.setPower(-1);
        if (gamepad2.dpad_left)
            wheelspin.setPower(0);
        if (gamepad2.dpad_right)
            wheelspin.setPower(0);






    }
    @Override
    public void stop() {
        lm_back.setPower(0);
        rm_back.setPower(0);
        lm_front.setPower(0);
        rm_front.setPower(0);
        spin_bot.setPower(0);
        wheelspin.setPower(0);

    }

}
