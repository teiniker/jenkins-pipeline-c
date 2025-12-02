# Jenkins Pipeline for C/C++ Applications

## Setup 

There a many ways to setup a Jenkins server - it depends on our use case.

### WAR File Setup 

A **WAR (Web Application Archive)** is a Java web application packaged for 
deployment. The Jenkins WAR can be run directly with a compatible Java 
runtime (for example, JDK 21) using `java -jar jenkins.war`, so we can 
start Jenkins without installing a separate application server.

* Download Jenkins Generic Java package (.war): [https://www.jenkins.io/download/](https://www.jenkins.io/download/) 

* In the download directory
    ```bash
    $ java -jar jenkins.war --httpPort=8080
    ```

* Browse to http://localhost:8080

* Follow the instructions to complete the installation

## Jenkins Job Configuration

We need the following settings for a new Jenkins job:

* New Item 
	- Pipeline
    - Description (optional)
    - Build Triggers 
	    - Poll SCM: `H/1 * * * *`
    - Pipeline / Definition: 
      - Pipeleine: Pipeline Script from SCM: 
        - SCM: Git 
        - Repository URL: `https://github.com/teiniker/jenkins-pipeline-c.git` 
        - Branches to build: `*/main` 
      - Script Path: Jenkinsfile

Save these settings.


## Jenkins Pipeline Syntax

A pipeline is a sequence of automated operations that usually represents a part of the software delivery and quality assurance process.

A Jenkins pipeline consists of two kinds of elements:
* **Step**: A single operation that tells Jenkins what to do.
	For example, check out code from the repository, execute a script .
* **Stage**: A logical separation of steps that groups conceptually distinct sequences of steps.
 	For example, Build, Test, and Deploy, used to visualize the Jenkins pipeline progress.

_Example_: Jenkins commit pipeline (checkout, build, and unit test)
```
pipeline 
{
    agent any 
    
    stages 
    {
        stage('build') 
        {
            steps 
            {
                sh 'make'
            }
        }
        stage('test') 
        {
            steps 
            {
               	sh 'build/stack_test'
            }
        }
    }
}
```

A **declarative pipeline** is always specified inside the `pipeline` block and contains sections, directives, and steps.

**Sections** define the pipeline structure and usually contain one or more directives or steps. They are defined with the following keywords: 

* **Stages**: This defines a series of one or more stage directives.

* **Steps**: This defines a series of one or more step instructions.

* **Post**: This defines a series of one or more step instructions that are run at the end of the pipeline build; they are marked with a condition (for example, always, success, or failure), and usually used to send notifications after the pipeline build (we will cover this in detail in the Triggers and notifications section).


**Directives** express the configuration of a pipeline or its parts: 

* **Agent**: This specifies where the execution takes place and can define the label to match the equally-labeled agents, or docker to specify a container that is dynamically provisioned to provide an environment for the pipeline execution. 

* **Triggers**: This defines automated ways to trigger the pipeline and can use cron to set the time-based scheduling, or pollSCM to check the repository for changes (we will cover this in detail in the Triggers and notifications section).

* **Options**: This specifies pipeline-specific options, for example, timeout (maximum time of pipeline run) or retry (number of times the pipeline should be re-run after failure).

* **Environment**: This defines a set of key values used as environment variables during the build.

* **Parameters**: This defines a list of user-input parameters.

* **Stage**: This allows for the logical grouping of steps.

* **When**: This determines whether the stage should be executed depending on the given condition.

### Steps 

Steps define the operations that are executed, so they actually tell Jenkins what to do: 

* **sh**: This executes the shell command; actually, it's possible to define almost any operation using `sh`. 

* **custom**: Jenkins offers a lot of operations that can be used as steps (for example, `echo`); many of them are simply wrappers over the sh command used for convenience; plugins can also define their own operations.

* **script**: This executes a block of the Groovy-based code that can be used for some non-trivial scenarios where flow control is needed.


## Commit Pipeline

The most **basic Continuous Integration process** is called a commit pipeline.

This phase starts with a commit (or push in Git) to the main repository and results in a report about 
the build success or failure. 

Since it runs after each change in the code, **the build should take no more than five minutes** and 
should consume a reasonable amount of resources.

The commit phase works as follows: a developer checks in the code to the repository, the Continuous Integration server detects the change, and the build starts. 
The most fundamental commit pipeline contains three stages: 
* **Checkout**: This stage downloads the source code from the repository. 

* **Compile**: This stage compiles the source code. 

* **Unit test**: This stage runs a suite of unit tests.


## Static Code Analysis 

**Cppcheck** is a static analysis tool for C/C++ code. 
It provides unique code analysis to detect bugs and focuses on detecting undefined 
behaviour and dangerous coding constructs.

Using the package manager, we can install cppcheck in one step:
```
$ sudo apt install cppcheck

$ cppcheck --version
Cppcheck 2.3
```


## References

* [YouTube: How to Install Jenkins](https://youtu.be/CEyfsQq3QEM)
* [YouTube: Complete Jenkins Pipeline Tutorial](https://youtu.be/7KCS70sCoK0)

* [Getting started with Pipeline](https://www.jenkins.io/doc/book/pipeline/getting-started/)

* [Using a Jenkinsfile](https://www.jenkins.io/doc/book/pipeline/jenkinsfile/)

* Rafał Leszko. **Continuous Delivery with Docker and Jenkins: Create secure applications by building complete CI/CD pipelines**. Packt Publishing, 2nd Edition 2019.

* [Cppcheck](https://cppcheck.sourceforge.io/)

*Egon Teiniker, 2022-2023, GPL v3.0* 
		
