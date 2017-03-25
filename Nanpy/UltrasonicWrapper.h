namespace nanpy {

	class UltrasonicWrapper {
		
		private:
			int echo, trig, conversionFactor;
			
		public:
			UltrasonicWrapper(int echoPin, int trigPin, bool useInches);
			float getDistance();
	};
}
