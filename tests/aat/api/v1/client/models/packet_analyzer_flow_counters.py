# coding: utf-8

"""
    OpenPerf API

    REST API interface for OpenPerf  # noqa: E501

    OpenAPI spec version: 1
    Contact: support@spirent.com
    Generated by: https://github.com/swagger-api/swagger-codegen.git
"""


import pprint
import re  # noqa: F401

import six


class PacketAnalyzerFlowCounters(object):
    """NOTE: This class is auto generated by the swagger code generator program.

    Do not edit the class manually.
    """

    """
    Attributes:
      swagger_types (dict): The key is attribute name
                            and the value is attribute type.
      attribute_map (dict): The key is attribute name
                            and the value is json key in definition.
    """
    swagger_types = {
        'errors': 'PacketAnalyzerFlowCountersErrors',
        'headers': 'list[PacketAnalyzerFlowHeader]',
        'frame_length': 'PacketAnalyzerFlowCountersFrameLength',
        'interarrival': 'PacketAnalyzerFlowCountersInterarrival',
        'jitter_ipdv': 'PacketAnalyzerFlowCountersJitterIpdv',
        'jitter_rfc': 'PacketAnalyzerFlowCountersJitterRfc',
        'latency': 'PacketAnalyzerFlowCountersLatency',
        'sequence': 'PacketAnalyzerFlowCountersSequence',
        'frame_count': 'int',
        'timestamp_first': 'datetime',
        'timestamp_last': 'datetime'
    }

    attribute_map = {
        'errors': 'errors',
        'headers': 'headers',
        'frame_length': 'frame_length',
        'interarrival': 'interarrival',
        'jitter_ipdv': 'jitter_ipdv',
        'jitter_rfc': 'jitter_rfc',
        'latency': 'latency',
        'sequence': 'sequence',
        'frame_count': 'frame_count',
        'timestamp_first': 'timestamp_first',
        'timestamp_last': 'timestamp_last'
    }

    def __init__(self, errors=None, headers=None, frame_length=None, interarrival=None, jitter_ipdv=None, jitter_rfc=None, latency=None, sequence=None, frame_count=None, timestamp_first=None, timestamp_last=None):  # noqa: E501
        """PacketAnalyzerFlowCounters - a model defined in Swagger"""  # noqa: E501

        self._errors = None
        self._headers = None
        self._frame_length = None
        self._interarrival = None
        self._jitter_ipdv = None
        self._jitter_rfc = None
        self._latency = None
        self._sequence = None
        self._frame_count = None
        self._timestamp_first = None
        self._timestamp_last = None
        self.discriminator = None

        if errors is not None:
            self.errors = errors
        if headers is not None:
            self.headers = headers
        if frame_length is not None:
            self.frame_length = frame_length
        if interarrival is not None:
            self.interarrival = interarrival
        if jitter_ipdv is not None:
            self.jitter_ipdv = jitter_ipdv
        if jitter_rfc is not None:
            self.jitter_rfc = jitter_rfc
        if latency is not None:
            self.latency = latency
        if sequence is not None:
            self.sequence = sequence
        self.frame_count = frame_count
        if timestamp_first is not None:
            self.timestamp_first = timestamp_first
        if timestamp_last is not None:
            self.timestamp_last = timestamp_last

    @property
    def errors(self):
        """Gets the errors of this PacketAnalyzerFlowCounters.  # noqa: E501


        :return: The errors of this PacketAnalyzerFlowCounters.  # noqa: E501
        :rtype: PacketAnalyzerFlowCountersErrors
        """
        return self._errors

    @errors.setter
    def errors(self, errors):
        """Sets the errors of this PacketAnalyzerFlowCounters.


        :param errors: The errors of this PacketAnalyzerFlowCounters.  # noqa: E501
        :type: PacketAnalyzerFlowCountersErrors
        """
        self._errors = errors

    @property
    def headers(self):
        """Gets the headers of this PacketAnalyzerFlowCounters.  # noqa: E501

        List of protocol headers  # noqa: E501

        :return: The headers of this PacketAnalyzerFlowCounters.  # noqa: E501
        :rtype: list[PacketAnalyzerFlowHeader]
        """
        return self._headers

    @headers.setter
    def headers(self, headers):
        """Sets the headers of this PacketAnalyzerFlowCounters.

        List of protocol headers  # noqa: E501

        :param headers: The headers of this PacketAnalyzerFlowCounters.  # noqa: E501
        :type: list[PacketAnalyzerFlowHeader]
        """
        self._headers = headers

    @property
    def frame_length(self):
        """Gets the frame_length of this PacketAnalyzerFlowCounters.  # noqa: E501


        :return: The frame_length of this PacketAnalyzerFlowCounters.  # noqa: E501
        :rtype: PacketAnalyzerFlowCountersFrameLength
        """
        return self._frame_length

    @frame_length.setter
    def frame_length(self, frame_length):
        """Sets the frame_length of this PacketAnalyzerFlowCounters.


        :param frame_length: The frame_length of this PacketAnalyzerFlowCounters.  # noqa: E501
        :type: PacketAnalyzerFlowCountersFrameLength
        """
        self._frame_length = frame_length

    @property
    def interarrival(self):
        """Gets the interarrival of this PacketAnalyzerFlowCounters.  # noqa: E501


        :return: The interarrival of this PacketAnalyzerFlowCounters.  # noqa: E501
        :rtype: PacketAnalyzerFlowCountersInterarrival
        """
        return self._interarrival

    @interarrival.setter
    def interarrival(self, interarrival):
        """Sets the interarrival of this PacketAnalyzerFlowCounters.


        :param interarrival: The interarrival of this PacketAnalyzerFlowCounters.  # noqa: E501
        :type: PacketAnalyzerFlowCountersInterarrival
        """
        self._interarrival = interarrival

    @property
    def jitter_ipdv(self):
        """Gets the jitter_ipdv of this PacketAnalyzerFlowCounters.  # noqa: E501


        :return: The jitter_ipdv of this PacketAnalyzerFlowCounters.  # noqa: E501
        :rtype: PacketAnalyzerFlowCountersJitterIpdv
        """
        return self._jitter_ipdv

    @jitter_ipdv.setter
    def jitter_ipdv(self, jitter_ipdv):
        """Sets the jitter_ipdv of this PacketAnalyzerFlowCounters.


        :param jitter_ipdv: The jitter_ipdv of this PacketAnalyzerFlowCounters.  # noqa: E501
        :type: PacketAnalyzerFlowCountersJitterIpdv
        """
        self._jitter_ipdv = jitter_ipdv

    @property
    def jitter_rfc(self):
        """Gets the jitter_rfc of this PacketAnalyzerFlowCounters.  # noqa: E501


        :return: The jitter_rfc of this PacketAnalyzerFlowCounters.  # noqa: E501
        :rtype: PacketAnalyzerFlowCountersJitterRfc
        """
        return self._jitter_rfc

    @jitter_rfc.setter
    def jitter_rfc(self, jitter_rfc):
        """Sets the jitter_rfc of this PacketAnalyzerFlowCounters.


        :param jitter_rfc: The jitter_rfc of this PacketAnalyzerFlowCounters.  # noqa: E501
        :type: PacketAnalyzerFlowCountersJitterRfc
        """
        self._jitter_rfc = jitter_rfc

    @property
    def latency(self):
        """Gets the latency of this PacketAnalyzerFlowCounters.  # noqa: E501


        :return: The latency of this PacketAnalyzerFlowCounters.  # noqa: E501
        :rtype: PacketAnalyzerFlowCountersLatency
        """
        return self._latency

    @latency.setter
    def latency(self, latency):
        """Sets the latency of this PacketAnalyzerFlowCounters.


        :param latency: The latency of this PacketAnalyzerFlowCounters.  # noqa: E501
        :type: PacketAnalyzerFlowCountersLatency
        """
        self._latency = latency

    @property
    def sequence(self):
        """Gets the sequence of this PacketAnalyzerFlowCounters.  # noqa: E501


        :return: The sequence of this PacketAnalyzerFlowCounters.  # noqa: E501
        :rtype: PacketAnalyzerFlowCountersSequence
        """
        return self._sequence

    @sequence.setter
    def sequence(self, sequence):
        """Sets the sequence of this PacketAnalyzerFlowCounters.


        :param sequence: The sequence of this PacketAnalyzerFlowCounters.  # noqa: E501
        :type: PacketAnalyzerFlowCountersSequence
        """
        self._sequence = sequence

    @property
    def frame_count(self):
        """Gets the frame_count of this PacketAnalyzerFlowCounters.  # noqa: E501

        Number of received packets  # noqa: E501

        :return: The frame_count of this PacketAnalyzerFlowCounters.  # noqa: E501
        :rtype: int
        """
        return self._frame_count

    @frame_count.setter
    def frame_count(self, frame_count):
        """Sets the frame_count of this PacketAnalyzerFlowCounters.

        Number of received packets  # noqa: E501

        :param frame_count: The frame_count of this PacketAnalyzerFlowCounters.  # noqa: E501
        :type: int
        """
        self._frame_count = frame_count

    @property
    def timestamp_first(self):
        """Gets the timestamp_first of this PacketAnalyzerFlowCounters.  # noqa: E501

        Timestamp of first received packet  # noqa: E501

        :return: The timestamp_first of this PacketAnalyzerFlowCounters.  # noqa: E501
        :rtype: datetime
        """
        return self._timestamp_first

    @timestamp_first.setter
    def timestamp_first(self, timestamp_first):
        """Sets the timestamp_first of this PacketAnalyzerFlowCounters.

        Timestamp of first received packet  # noqa: E501

        :param timestamp_first: The timestamp_first of this PacketAnalyzerFlowCounters.  # noqa: E501
        :type: datetime
        """
        self._timestamp_first = timestamp_first

    @property
    def timestamp_last(self):
        """Gets the timestamp_last of this PacketAnalyzerFlowCounters.  # noqa: E501

        Timestamp of last received packet  # noqa: E501

        :return: The timestamp_last of this PacketAnalyzerFlowCounters.  # noqa: E501
        :rtype: datetime
        """
        return self._timestamp_last

    @timestamp_last.setter
    def timestamp_last(self, timestamp_last):
        """Sets the timestamp_last of this PacketAnalyzerFlowCounters.

        Timestamp of last received packet  # noqa: E501

        :param timestamp_last: The timestamp_last of this PacketAnalyzerFlowCounters.  # noqa: E501
        :type: datetime
        """
        self._timestamp_last = timestamp_last

    def to_dict(self):
        """Returns the model properties as a dict"""
        result = {}

        for attr, _ in six.iteritems(self.swagger_types):
            value = getattr(self, attr)
            if isinstance(value, list):
                result[attr] = list(map(
                    lambda x: x.to_dict() if hasattr(x, "to_dict") else x,
                    value
                ))
            elif hasattr(value, "to_dict"):
                result[attr] = value.to_dict()
            elif isinstance(value, dict):
                result[attr] = dict(map(
                    lambda item: (item[0], item[1].to_dict())
                    if hasattr(item[1], "to_dict") else item,
                    value.items()
                ))
            else:
                result[attr] = value
        if issubclass(PacketAnalyzerFlowCounters, dict):
            for key, value in self.items():
                result[key] = value

        return result

    def to_str(self):
        """Returns the string representation of the model"""
        return pprint.pformat(self.to_dict())

    def __repr__(self):
        """For `print` and `pprint`"""
        return self.to_str()

    def __eq__(self, other):
        """Returns true if both objects are equal"""
        if not isinstance(other, PacketAnalyzerFlowCounters):
            return False

        return self.__dict__ == other.__dict__

    def __ne__(self, other):
        """Returns true if both objects are not equal"""
        return not self == other
