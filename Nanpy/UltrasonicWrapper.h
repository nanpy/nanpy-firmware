namespace nanpy {

	class UltrasonicWrapper {
		
		private:
			int echo, trig;
			bool useInches;
			
		public:
			UltrasonicWrapper(int echoPin, int trigPin, bool useInchesParam);
			float getDistance();
			bool readingInRange(float low, float high);
	};
}
