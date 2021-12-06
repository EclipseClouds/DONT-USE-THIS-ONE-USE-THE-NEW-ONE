package org.firstinspires.ftc.teamcode;

import static com.qualcomm.robotcore.hardware.DcMotor.RunMode.RUN_USING_ENCODERS;

import com.qualcomm.hardware.bosch.BNO055IMU;
import com.qualcomm.robotcore.eventloop.opmode.Disabled;
import com.qualcomm.robotcore.eventloop.opmode.OpMode;
import com.qualcomm.robotcore.eventloop.opmode.TeleOp;
import com.qualcomm.robotcore.hardware.DcMotor;
import com.qualcomm.robotcore.hardware.DcMotorSimple;
import com.qualcomm.robotcore.hardware.Servo;
import com.qualcomm.robotcore.util.ElapsedTime;
import com.qualcomm.robotcore.eventloop.opmode.LinearOpMode;
import com.qualcomm.robotcore.util.Range;
import org.firstinspires.ftc.robotcore.external.navigation.AngleUnit;
import org.firstinspires.ftc.robotcore.external.navigation.AxesOrder;
import org.firstinspires.ftc.robotcore.external.navigation.AxesReference;
import org.firstinspires.ftc.robotcore.external.navigation.Orientation;



import org.firstinspires.ftc.robotcore.external.navigation.Orientation;


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
    private Servo armservo = null;
    private double servoposition = 0;
    // 0.5 is the ideal position for intake
    static final double MAX_POS = 0.55;
    static final double MIN_POS = 0.45;
    private DcMotor wheelspin = null;
    BNO055IMU imu;
    Orientation angles;
    boolean arm_movedup = false;
    boolean arm_moveddown = true;
    boolean arm_uphalf = false;
    boolean arm_downhalf = false;

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
        spin_bot = hardwareMap.get(DcMotor.class, "intake");
        spin_bot.setDirection(DcMotorSimple.Direction.REVERSE);
        arm = hardwareMap.get(DcMotor.class, "arm");
        armservo = hardwareMap.get(Servo.class, "armservo");
        wheelspin = hardwareMap.get(DcMotor.class, "wheelspin");
        arm.setMode(DcMotor.RunMode.RUN_USING_ENCODER);
        arm.setMode(DcMotor.RunMode.STOP_AND_RESET_ENCODER);
        boolean arm_movedup = false;
        boolean arm_moveddown = true;

        //int gamepad2x_push = 0;
        armservo.setPosition(0.4);

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
        /*
        BNO055IMU.Parameters parameters = new BNO055IMU.Parameters();
        parameters.angleUnit = BNO055IMU.AngleUnit.DEGREES;
        imu = hardwareMap.get(BNO055IMU.class, "imu");
        imu.initialize(parameters);

        */

        double r = Math.hypot(gamepad1.left_stick_x, gamepad1.left_stick_y);
        double robotAngle = Math.atan2(gamepad1.left_stick_y * -1, (gamepad1.left_stick_x)) - Math.PI / 4;
        double rightX = gamepad1.right_stick_x * -1;
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

        int small_level = 1000;
        int decrease_small_big_level = -2600;
        int small_big_level = 2600;
        int decrease_small_level = -1000;
        int currentArmPosition = 0;

        /*
        if (gamepad2.x == true)
        {
            telemetry.addData("entered gamepad2 section:", "entered");
            currentArmPosition = arm.getCurrentPosition();
            telemetry.addData("Current Position", currentArmPosition);
            arm.setTargetPosition(currentArmPosition + first_level);
//            arm.setMode(DcMotor.RunMode.RUN_TO_POSITION);
//            arm.setPower(0.02);
//
//            while (arm.isBusy())
//            {
//                telemetry.addData("Goal:",  "Running to %7d", currentArmPosition + first_level);
//                telemetry.addData("Current:",  "Running at %7d", arm.getCurrentPosition());
//                telemetry.update();
//            }
//            telemetry.addData("Slide", "Complete");
//            arm.setPower(0);
//            arm.setMode(DcMotor.RunMode.RUN_USING_ENCODER);
//
        }

         */

        if (gamepad2.a == true && arm_movedup == true)
        {
            arm.setMode(DcMotor.RunMode.STOP_AND_RESET_ENCODER);
            arm.setTargetPosition((int)decrease_small_big_level);
            arm.setPower(0.5);
            arm.setMode(DcMotor.RunMode.RUN_TO_POSITION);
            while (arm.isBusy())
            {
            }
            arm.setPower(0);
            arm.setMode(DcMotor.RunMode.RUN_USING_ENCODER);
            arm_movedup = false;
            arm_downhalf = true;
        }


        if (gamepad2.b == true && arm_downhalf == true)
        {
            arm.setMode(DcMotor.RunMode.STOP_AND_RESET_ENCODER);
            arm.setTargetPosition((int)decrease_small_level);
            arm.setPower(0.5);
            arm.setMode(DcMotor.RunMode.RUN_TO_POSITION);
            while (arm.isBusy())
            {
            }
            arm.setPower(0);
            arm.setMode(DcMotor.RunMode.RUN_USING_ENCODER);
            arm_downhalf = false;
            arm_moveddown = true;
            armservo.setPosition(0.5);
        }

        if (gamepad2.x == true && arm_moveddown == true)
        {
            arm.setMode(DcMotor.RunMode.STOP_AND_RESET_ENCODER);
            arm.setTargetPosition((int)small_level);
            arm.setPower(0.5);
            arm.setMode(DcMotor.RunMode.RUN_TO_POSITION);
            while (arm.isBusy())
            {
            }
            arm.setPower(0);
            arm.setMode(DcMotor.RunMode.RUN_USING_ENCODER);
            arm_uphalf = true;
            arm_moveddown = false;
        }

        if (gamepad2.y == true && arm_uphalf == true)
        {
            arm.setMode(DcMotor.RunMode.STOP_AND_RESET_ENCODER);
            arm.setTargetPosition((int)small_big_level);
            arm.setPower(0.5);
            arm.setMode(DcMotor.RunMode.RUN_TO_POSITION);
            while (arm.isBusy())
            {
            }
            arm.setPower(0);
            arm.setMode(DcMotor.RunMode.RUN_USING_ENCODER);
            arm_movedup = true;
            arm_uphalf = false;
        }



        if (gamepad2.left_bumper)
        {
            armservo.setPosition(0.4);
        }
        if (gamepad2.right_bumper)
        {
            armservo.setPosition(0);
        }

        telemetry.addData("servo", "%.2f", servoposition);
        if (gamepad2.dpad_up)
            wheelspin.setPower(1);
        if (gamepad2.dpad_down)
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
