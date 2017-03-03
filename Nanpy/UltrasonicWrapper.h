namespace nanpy {

	class UltrasonicWrapper {
		
		private:
			int echo, trig;
			bool useInches;
			
		public:
			UltrasonicWrapper(int echoPin, int trigPin, bool useInchesParam);
			int getDistance();
			int readInRange(int low, int high);
	}
}