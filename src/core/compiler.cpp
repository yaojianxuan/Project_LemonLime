/*
 * SPDX-FileCopyrightText: 2011-2018 Project Lemon, Zhipeng Jia
 *                         2018-2019 Project LemonPlus, Dust1404
 *                         2019      Project LemonLime
 *
 * SPDX-License-Identifier: GPL-3.0-or-later
 *
 */

#include "compiler.h"

#if QT_VERSION >= QT_VERSION_CHECK(5, 14, 0)
#define QT_SkipEmptyParts Qt::SkipEmptyParts
#else
#define QT_SkipEmptyParts QString::SkipEmptyParts
#endif

Compiler::Compiler(QObject *parent) : QObject(parent)
{
	compilerType = Typical;
	timeLimitRatio = 1;
	memoryLimitRatio = 1;
	disableMemoryLimitCheck = false;
}

auto Compiler::getCompilerType() const -> Compiler::CompilerType { return compilerType; }

auto Compiler::getCompilerName() const -> const QString & { return compilerName; }

auto Compiler::getSourceExtensions() const -> const QStringList & { return sourceExtensions; }

auto Compiler::getCompilerLocation() const -> const QString & { return compilerLocation; }

auto Compiler::getInterpreterLocation() const -> const QString & { return interpreterLocation; }

auto Compiler::getBytecodeExtensions() const -> const QStringList & { return bytecodeExtensions; }

auto Compiler::getConfigurationNames() const -> const QStringList & { return configurationNames; }

auto Compiler::getCompilerArguments() const -> const QStringList & { return compilerArguments; }

auto Compiler::getInterpreterArguments() const -> const QStringList & { return interpreterArguments; }

auto Compiler::getEnvironment() const -> const QProcessEnvironment & { return environment; }

auto Compiler::getTimeLimitRatio() const -> double { return timeLimitRatio; }

auto Compiler::getMemoryLimitRatio() const -> double { return memoryLimitRatio; }

auto Compiler::getDisableMemoryLimitCheck() const -> bool { return disableMemoryLimitCheck; }

void Compiler::setCompilerType(Compiler::CompilerType type) { compilerType = type; }

void Compiler::setCompilerName(const QString &name) { compilerName = name; }

void Compiler::setSourceExtensions(const QString &extensions)
{
	sourceExtensions = extensions.split(";", QT_SkipEmptyParts);
}

void Compiler::setCompilerLocation(const QString &location) { compilerLocation = location; }

void Compiler::setInterpreterLocation(const QString &location) { interpreterLocation = location; }

void Compiler::setBytecodeExtensions(const QString &extensions)
{
	bytecodeExtensions = extensions.split(";", QT_SkipEmptyParts);
}

void Compiler::setEnvironment(const QProcessEnvironment &env) { environment = env; }

void Compiler::setTimeLimitRatio(double ratio) { timeLimitRatio = ratio; }

void Compiler::setMemoryLimitRatio(double ratio) { memoryLimitRatio = ratio; }

void Compiler::setDisableMemoryLimitCheck(bool check) { disableMemoryLimitCheck = check; }

void Compiler::addConfiguration(const QString &name, const QString &arguments1, const QString &arguments2)
{
	configurationNames.append(name);
	compilerArguments.append(arguments1);
	interpreterArguments.append(arguments2);
}

void Compiler::setConfigName(int index, const QString &name)
{
	if (0 <= index && index < configurationNames.size())
	{
		configurationNames[index] = name;
	}
}

void Compiler::setCompilerArguments(int index, const QString &arguments)
{
	if (0 <= index && index < compilerArguments.size())
	{
		compilerArguments[index] = arguments;
	}
}

void Compiler::setInterpreterArguments(int index, const QString &arguments)
{
	if (0 <= index && index < interpreterArguments.size())
	{
		interpreterArguments[index] = arguments;
	}
}

void Compiler::deleteConfiguration(int index)
{
	if (0 <= index && index < configurationNames.size())
	{
		configurationNames.removeAt(index);
		compilerArguments.removeAt(index);
		interpreterArguments.removeAt(index);
	}
}

void Compiler::copyFrom(Compiler *other)
{
	compilerType = other->getCompilerType();
	compilerName = other->getCompilerName();
	sourceExtensions = other->getSourceExtensions();
	compilerLocation = other->getCompilerLocation();
	interpreterLocation = other->getInterpreterLocation();
	bytecodeExtensions = other->getBytecodeExtensions();
	configurationNames = other->getConfigurationNames();
	compilerArguments = other->getCompilerArguments();
	interpreterArguments = other->getInterpreterArguments();
	environment = other->getEnvironment();
	timeLimitRatio = other->getTimeLimitRatio();
	memoryLimitRatio = other->getMemoryLimitRatio();
	disableMemoryLimitCheck = other->getDisableMemoryLimitCheck();
}
