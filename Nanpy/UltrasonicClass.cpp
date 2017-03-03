void nanpy::UltrasonicClass::elaborate( MethodDescriptor* m ) {
	ObjectsManager<UltrasonicWrapper>::elaborate(m);
	
	if (strcmp(m->getName(), "new") == 0) {
		v.insert(new UltrasonicWrapper(m->getInt(0), m->getInt(1), m->getBool(2)));
		m->returns(v.getLastIndex());
	}
	
	if (strcmp(m->getName(), "get_distance") == 0) {
		m->returns(v[m->getObjectId()]->getDistance());
	}
	
	if (strcmp(m->getName(), "read_in_range") == 0) {
		m->returns(v[m->getObjectId()]->readInRange(m->getInt(0), m->getInt(1)));
	}
}
