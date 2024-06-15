

#pragma once

class BirdFactory
{
public:
	virtual Flyer* factory(Type type) {}
};

class BirdFactoryLevel1 : public BirdFactory
{
public:
	Flyer* factory(Type type) override;
};

class BirdFactoryLevel2 : public BirdFactory
{
public:
	Bird* factory(BirdType type) override;
};

class BirdFactoryLevel3 : public BirdFactory
{
public:
	Bird* factory(BirdType type) override;
};

class BirdFactoryLevel4 : public BirdFactory
{
public:
	Bird* factory(BirdType type) override;
};
