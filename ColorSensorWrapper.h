namespace nanpy {

  class ColorSensorWrapper {

  private:
    int s0, s1, s2, s3, sensorOut;

  public:
    ColorSensorWrapper(int s0, int s1, int s2, int s3, int sensorOut);
    int getColor(char color);
  };
}
