#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup() {

	ofSetFrameRate(25);
	ofSetWindowTitle("openFrameworks");

	ofBackground(239);
	ofSetLineWidth(3);
	ofEnableBlendMode(ofBlendMode::OF_BLENDMODE_MULTIPLY);
}

//--------------------------------------------------------------
void ofApp::update() {

	ofSeedRandom(1000);
}

//--------------------------------------------------------------
void ofApp::draw() {

	ofTranslate(ofGetWindowSize() * 0.5);

	ofColor color;
	for (int hue = 0; hue < 256; hue += 16) {

		auto noise_p = ofRandom(1000);
		auto deg_start = ofMap(hue, 0, 255, 0, 360);

		color.setHsb(hue, 200, 255);
		ofSetColor(color);
		
		hue % 32 == 0 ? ofFill() : ofNoFill();
		
		ofBeginShape();
		for (int deg = deg_start; deg < deg_start + 360; deg += 120) {

			auto noise_location = glm::vec4(noise_p, cos(deg * DEG_TO_RAD) * 0.5, sin(deg * DEG_TO_RAD) * 0.5, ofGetFrameNum() * 0.02);
			auto radius = ofMap(ofNoise(noise_location), 0, 1, -550, 550);

			auto location = glm::vec2(radius * cos(deg * DEG_TO_RAD), radius * sin(deg * DEG_TO_RAD));
			ofVertex(location);
		}
		ofEndShape();
	}

	/*
	int start = 75;
	if (ofGetFrameNum() > start) {

		ostringstream os;
		os << setw(4) << setfill('0') << ofGetFrameNum() - start;
		ofImage image;
		image.grabScreen(0, 0, ofGetWidth(), ofGetHeight());
		image.saveImage("image/cap/img_" + os.str() + ".jpg");
		if (ofGetFrameNum() - start >= 25 * 20) {

			std::exit(1);
		}
	}
	*/
}


//--------------------------------------------------------------
int main() {

	ofSetupOpenGL(720, 720, OF_WINDOW);
	ofRunApp(new ofApp());
}