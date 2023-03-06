#include <ros.h>
#include <std_msgs/UInt8MultiArray.h>
#include <servo_control.h>

#define DEBUG_CONSOLE

void reset_mid_servo() {
	uint8_t right_arm_angle[6] = {RHAND_FINGER_1_MIN, RHAND_FINGER_2_MIN, RHAND_FINGER_3_MIN, RHAND_FINGER_4_MIN, RHAND_FINGER_5_MIN, RHAND_WRIST_MID};
	uint8_t state_right_arm[6] = {};
	right_arm_control(right_arm_angle, state_right_arm);

	// uint8_t left_arm_angle[6] = {LHAND_FINGER_1_MIN, LHAND_FINGER_2_MIN, LHAND_FINGER_2_MIN, LHAND_FINGER_2_MIN, LHAND_FINGER_2_MIN, LHAND_WRIST_MID};
	// left_arm_control(left_arm_angle, state);

	uint8_t right_shoulder_angle[4] = {RHAND_BICEPS_MID, RSHOUL_ROTAT_MID, RSHOUL_UD_MID, RSHOUL_TILT_MID};
	uint8_t state_right_shoulder[4] = {};
	right_shoulder_control(right_shoulder_angle, state_right_shoulder);

	uint8_t head_angle[4] = {HEAD_MOUTH_MID, HEAD_EYE_ROTAT_MID, HEAD_EYE_TILT_MID, HEAD_ROTAT_MID};
	uint8_t state_head[4] = {};
	head_control(head_angle, state_head);

	uint8_t neck_angle[3] = {NECK_RIGHT_MID, NECK_LEFT_MID, NECK_MID_MID};
	uint8_t state_neck[3] = {};
	neck_control(neck_angle, state_neck);
}

ros::NodeHandle  nh;

void right_arm( const std_msgs::UInt8MultiArray& cmd_msg) {
	uint8_t state[6] = {};
	right_arm_control(cmd_msg.data, state);
	for (uint8_t i = 0; i < 6; i++) {
		if (state[i] == SERVO_LIMIT_MIN) {
			String str = String("RIGHT_ARM_LIM_MIN - ") + (i + 1);
			nh.logwarn(str.c_str());
		} else if (state[i] == SERVO_LIMIT_MAX) {
			String str = String("RIGHT_ARM_LIM_MAX - ") + (i + 1);
			nh.logwarn(str.c_str());
		} 
	} 
#ifdef DEBUG_CONSOLE
	String _str;
	_str += "RIGHT_ARM - ";
	for (uint8_t i = 0; i < 6; i++) {
		_str += cmd_msg.data[i];
		_str += " ";
	}
	nh.loginfo(_str.c_str());
#endif
}

void left_arm( const std_msgs::UInt8MultiArray& cmd_msg) {
	uint8_t state[6] = {};
	left_arm_control(cmd_msg.data, state);
	for (uint8_t i = 0; i < 6; i++) {
		if (state[i] == SERVO_LIMIT_MIN) {
			String str = String("LEFT_ARM_LIM_MIN - ") + (i + 1);
			nh.logwarn(str.c_str());
		} else if (state[i] == SERVO_LIMIT_MAX) {
			String str = String("LEFT_LIMIT_MAX - ") + (i + 1);
			nh.logwarn(str.c_str());
		} 
	} 
#ifdef DEBUG_CONSOLE
	String _str;
	_str += "LEFT_ARM - ";
	for (uint8_t i = 0; i < 6; i++) {
		_str += cmd_msg.data[i];
		_str += " ";
	}
	nh.loginfo(_str.c_str());
#endif
}

void right_shoulder( const std_msgs::UInt8MultiArray& cmd_msg) {
	uint8_t state[4] = {};
	right_shoulder_control(cmd_msg.data, state);
	for (uint8_t i = 0; i < 4; i++) {
		if (state[i] == SERVO_LIMIT_MIN) {
			String str = String("RIGHT_SHOULDER_LIM_MIN - ") + (i + 1);
			nh.logwarn(str.c_str());
		} else if (state[i] == SERVO_LIMIT_MAX) {
			String str = String("RIGHT_SHOULDER_MAX - ") + (i + 1);
			nh.logwarn(str.c_str());
		} 
	} 
#ifdef DEBUG_CONSOLE
	String _str;
	_str += "RIGHT_SHOULDER - ";
	for (uint8_t i = 0; i < 4; i++) {
		_str += cmd_msg.data[i];
		_str += " ";
	}
	nh.loginfo(_str.c_str());
#endif
}

void left_shoulder ( const std_msgs::UInt8MultiArray& cmd_msg) {
	uint8_t state[4] = {};
	left_shoulder_control(cmd_msg.data, state);
	for (uint8_t i = 0; i < 4; i++) {
		if (state[i] == SERVO_LIMIT_MIN) {
			String str = String("LEFT_SHOULDER_LIM_MIN - ") + (i + 1);
			nh.logwarn(str.c_str());
		} else if (state[i] == SERVO_LIMIT_MAX) {
			String str = String("LEFT_SHOULDER_MAX - ") + (i + 1);
			nh.logwarn(str.c_str());
		} 
	} 
#ifdef DEBUG_CONSOLE
	String _str;
	_str += "LEFT_SHOULDER - ";
	for (uint8_t i = 0; i < 4; i++) {
		_str += cmd_msg.data[i];
		_str += " ";
	}
	nh.loginfo(_str.c_str());
#endif
}

void head ( const std_msgs::UInt8MultiArray& cmd_msg) {
	uint8_t state[4] = {};
	head_control(cmd_msg.data, state);
	for (uint8_t i = 0; i < 4; i++) {
		if (state[i] == SERVO_LIMIT_MIN) {
			String str = String("HEAD_LIM_MIN - ") + (i + 1);
			nh.logwarn(str.c_str());
		} else if (state[i] == SERVO_LIMIT_MAX) {
			String str = String("HEAD_MAX_LIM - ") + (i + 1);
			nh.logwarn(str.c_str());
		}
	}
#ifdef DEBUG_CONSOLE
	String _str;
	_str += "HEAD - ";
	for (uint8_t i = 0; i < 4; i++) {
		_str += cmd_msg.data[i];
		_str += " ";
	}
	nh.loginfo(_str.c_str());
#endif
}

void neck ( const std_msgs::UInt8MultiArray& cmd_msg) {
	uint8_t state[3] = {};
	neck_control(cmd_msg.data, state);
	for (uint8_t i = 0; i < 3; i++) {
		if (state[i] == SERVO_LIMIT_MIN) {
			String str = String("NECK_LIM_MIN - ") + (i + 1);
			nh.logwarn(str.c_str());
		} else if (state[i] == SERVO_LIMIT_MAX) {
			String str = String("NECK_MAX_LIM - ") + (i + 1);
			nh.logwarn(str.c_str());
		} 
	} 
#ifdef DEBUG_CONSOLE
	String _str;
	_str += "NECK - ";
	for (uint8_t i = 0; i < 3; i++) {
		_str += cmd_msg.data[i];
		_str += " ";
	}
	nh.loginfo(_str.c_str());
#endif
}

void test ( const std_msgs::UInt8MultiArray& cmd_msg) {

	servo_HEAD_MOUTH.attach(HEAD_MOUTH_PIN);
	servo_HEAD_EYE_ROTAT.attach(HEAD_EYE_ROTAT_PIN);
	servo_HEAD_EYE_TILT.attach(HEAD_EYE_TILT_PIN);
    servo_HEAD_ROTAT.attach(HEAD_ROTAT_PIN);

    servo_HEAD_MOUTH.write(cmd_msg.data[0]);
    servo_HEAD_EYE_ROTAT.write(cmd_msg.data[1]);
    servo_HEAD_EYE_TILT.write(cmd_msg.data[2]);
    servo_HEAD_ROTAT.write(cmd_msg.data[3]);

}

ros::Subscriber<std_msgs::UInt8MultiArray> sub_right_arm("right_arm", right_arm);
ros::Subscriber<std_msgs::UInt8MultiArray> sub_left_arm("left_arm", left_arm);
ros::Subscriber<std_msgs::UInt8MultiArray> sub_right_shoulder("right_shoulder", right_shoulder);
ros::Subscriber<std_msgs::UInt8MultiArray> sub_left_shoulder("left_shoulder", left_shoulder);
ros::Subscriber<std_msgs::UInt8MultiArray> sub_head("head", head);
ros::Subscriber<std_msgs::UInt8MultiArray> sub_neck("neck", neck);
ros::Subscriber<std_msgs::UInt8MultiArray> sub_test("test", test);

void setup(){
	nh.initNode();
	reset_mid_servo();
	delay(1500);
	nh.loginfo("READY");
	nh.subscribe(sub_right_arm);
	nh.subscribe(sub_left_arm);
	nh.subscribe(sub_right_shoulder);
	nh.subscribe(sub_left_shoulder);
	nh.subscribe(sub_head);
	nh.subscribe(sub_neck);

	nh.subscribe(sub_test);
}

void loop(){
	nh.spinOnce();
	delay(1);
}
